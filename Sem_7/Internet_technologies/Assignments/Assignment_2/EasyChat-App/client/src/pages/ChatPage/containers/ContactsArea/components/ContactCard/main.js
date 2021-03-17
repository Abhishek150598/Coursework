import React, { Component } from 'react';
import ListItem from '@material-ui/core/ListItem';
import ListItemText from '@material-ui/core/ListItemText';
import ListItemAvatar from '@material-ui/core/ListItemAvatar';
import Avatar from '@material-ui/core/Avatar';
import Divider from '@material-ui/core/Divider';
import Button from '@material-ui/core/Button';
import Badge from '@material-ui/core/Badge';
import './main.css';

class ContactCard extends Component {

    render() {
        const { contactName, topMessage, unread, displayImage, updateCurrentContact } = this.props;
        const topMessageSliced = (topMessage.length > 30) ? topMessage.substring(0, 30) + "..." : topMessage;
        return (
            <div className='contactCard'>
                <Button 
                    fullWidth
                    onClick={() => {updateCurrentContact(contactName)}}
                >
                    <ListItem>
                        <ListItemAvatar>
                            <Badge badgeContent={unread} color="primary">
                                <Avatar alt={contactName} src={displayImage} />
                            </Badge>
                        </ListItemAvatar>
                        <ListItemText primary={contactName} secondary={topMessageSliced} />
                    </ListItem>
                </Button>
                <Divider />
                
            </div>
        );
    }
    
}

export default ContactCard;
