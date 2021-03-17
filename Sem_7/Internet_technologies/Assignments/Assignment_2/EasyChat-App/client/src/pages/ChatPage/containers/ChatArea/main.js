import React, { Component } from 'react';
import Message from './components/Message/main';

import './main.css';

class ChatArea extends Component {
    
    render() { 
        const user = sessionStorage.getItem("User");
        const { messages } = this.props;
        console.log(messages);
        return (
            <div className = 'chatArea'>
                {messages.map(({_id, from, body, createdAt}) => 
                    <Message key = {_id}
                        sender = {(from === user) ? 'You' : from} 
                        time = {createdAt.match(/\d\d:\d\d/)[0]}
                        message = {body}
                    />
                )}
            </div>
        );
    }
}
 
export default ChatArea;