import React, { Component } from 'react';
import './main.css';
import ContactCard from './components/ContactCard/main';
import List from '@material-ui/core/List';


class ContactsArea extends Component {
    
    render() { 
        const { contacts, updateCurrentContact } = this.props;
        return (
            <div className = 'contactsArea'>
                <List>
                    {contacts.map(({name, lastMessage, unread}) => 
                        <ContactCard 
                            key = {name}
                            contactName = {name} 
                            topMessage = {lastMessage} 
                            unread = {unread}
                            displayImage = 'img1.jpg'
                            updateCurrentContact = {updateCurrentContact}
                        />
                    )}
                </List>
            </div>
        );
    }
}
 
export default ContactsArea;