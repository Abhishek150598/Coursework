import React, { Component } from 'react';
import HeaderArea from './containers/HeaderArea/main';
import SearchArea from './containers/SearchArea/main';
import ContactsArea from './containers/ContactsArea/main';
import ChatArea from './containers/ChatArea/main';
import TextArea from './containers/TextArea/main';
import ContactHeader from './containers/ContactHeader/main';
import getUsersList from '../../services/getUsersList';
import getContactsList from '../../services/getContactsList';
import getMessageHistory from '../../services/getMessageHistory';
import makeToast from '../NotificationToast/main';
import io from "socket.io-client";
import './main.css';


class ChatPage extends Component {
    state = {
        currentContact: 'Broadcast Channel',
        users: [],
        contacts: [],
        messages: [],
        socket: null,
    }

    updateContacts = async () => {
        // Getting the list of contacts of logged in user
        const contacts =await getContactsList();
        console.log("Contacts updated successfully");
        this.setState({contacts});    
    };

    updateMessages = async () => {
        const contactName = this.state.currentContact;
        // Getting the messages of current contact
        const messages = await getMessageHistory(contactName);
        console.log("Messages updated successfully");
        this.setState({messages});
    }

    updateUsers = async () => {
        // Getting the list of global users
        const users = await getUsersList();
        console.log("Users updated successfully");
        this.setState({users});
    }

    updateCurrentContact = async (newContact) => {
        await this.setState({currentContact: newContact})
        await this.updateMessages();
        await this.updateContacts();
    };

    sendMessage = async (message) => {
        if (this.state.socket) {
            await this.state.socket.emit("message", {
                to: this.state.currentContact,
                message: message,
            });
            console.log("Message emission successful");
            await this.updateMessages();
            console.log("Calling updateMessages() succesful");
            await this.updateContacts();   
            console.log("Calling updateContacts() succesful");
        }
        else {
            makeToast("error", "Message sending failed");
            console.log("Message sending failed");
            await this.setupSocket();
            await this.sendMessage(message);
        }
    }

    setupSocket = () => {
        const token = sessionStorage.getItem("AuthToken");
        if (token && !this.state.socket) {
            const newSocket = io("http://localhost:8000", {
                query: {
                    token: sessionStorage.getItem("AuthToken"),
                },
            });
    
            newSocket.on("disconnect", () => {
                this.setState({socket: null});
                console.log("Socket disconnected");
                makeToast("error", "Socket disconnected");
                setTimeout(this.setupSocket, 3000);
            });
    
            newSocket.on("connect", () => {
                makeToast("success", "Socket connected");
                console.log("Socket connected");
            });
          
            newSocket.on("message", async (message, from) => {
                await this.updateMessages();
                await this.updateContacts();
            });

            newSocket.on("ack", () => {
                console.log("Acknowledgement received")
            });
            this.setState({socket: newSocket});
        }
      }
    
    async componentDidMount() {
        this.setupSocket()
        this.updateUsers()
        this.updateMessages()
        this.updateContacts()

    }

    logoutUser = () => {
        sessionStorage.removeItem("AuthToken");
        sessionStorage.removeItem("User");
        makeToast("success", "Successfully logged out");
        this.props.history.push("/");
    }

    render() {
        console.log("Render function called");
        const { currentContact, users, contacts, messages } = this.state;
        return (
            <div className = 'chatPage'>
                <div className = 'leftArea'>
                    <HeaderArea 
                        logoutUser = {this.logoutUser}
                    />
                    <SearchArea 
                        users = {users} 
                        updateCurrentContact = {this.updateCurrentContact}
                    />
                    <ContactsArea 
                        contacts = {contacts}
                        updateCurrentContact = {this.updateCurrentContact}
                    />
                </div>
                <div className = 'rightArea'>
                    <ContactHeader 
                        name = {currentContact} 
                        displayImage = 'abc.jpg'
                    />
                    <ChatArea 
                        id = 'chatArea'
                        messages = {messages}
                    />
                    <TextArea sendMessage = {this.sendMessage}/>
                </div>
            </div>
        );
    }    
}

export default ChatPage;
