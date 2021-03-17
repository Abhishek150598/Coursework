import React, { Component } from 'react';
import { Avatar } from '@material-ui/core';
import Typography from '@material-ui/core/Typography';
import AppBar from '@material-ui/core/AppBar';
import Toolbar from '@material-ui/core/Toolbar';
import IconButton from '@material-ui/core/IconButton';
import SearchIcon from '@material-ui/icons/Search';
import MoreIcon from '@material-ui/icons/MoreVert';
import './main.css';

class ContactHeader extends Component {
    render() { 
        const { name, displayImage } = this.props;
        return (
            <div className = 'contactHeader'>
                <AppBar position="static" color = "secondary">
                    <Toolbar className = 'toolbar'>
                        
                        <div className = 'nameAndAvatar'>
                            <Avatar alt={name} src={displayImage} />
                            <Typography variant="h6" className = 'contactName'>
                                {name}
                            </Typography>
                        </div>
                        <div className = 'icons' float = 'right'>
                            <IconButton color="inherit">
                                <SearchIcon />
                            </IconButton>
                            <IconButton edge="end" color="inherit">
                                <MoreIcon />
                            </IconButton>
                        </div>
                    </Toolbar>
                </AppBar>
            </div>
        );
    }
}
 
export default ContactHeader;