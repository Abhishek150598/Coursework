import React, { Component } from 'react';
import './main.css';

class Message extends Component {
    render() { 
        const { sender, time, message } = this.props;
        const className = (sender === 'You') ? 'sentMessageDiv' : 'receivedMessageDiv';
        return ( 
            <div className = {className + ' messageDiv'}> 
                <div className = 'header'>
                    <h5 className = 'sender'>{sender}</h5>
                    <p className = 'time'>{time}</p>
                </div>
                <div className = 'body'>
                    <p className = 'message'>{message}</p> 
                </div>    
            </div> 
        );
    }
}
 
export default Message;