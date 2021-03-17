import React, { Component } from 'react';
import Typography from '@material-ui/core/Typography';
import AppBar from '@material-ui/core/AppBar';
import Toolbar from '@material-ui/core/Toolbar';
import IconButton from '@material-ui/core/IconButton';
import SettingsIcon from '@material-ui/icons/Settings';
import AccountCircleRoundedIcon from '@material-ui/icons/AccountCircleRounded';
import './main.css';

class HeaderArea extends Component {

    render() { 
        const user = sessionStorage.getItem("User");
        return (
            <div className = 'headerArea'>
                <AppBar position="static" color = "primary">
                    <Toolbar className = 'toolbar'>
                        <Typography variant="h6">
                            {'Welcome ' + user + "!"}
                        </Typography>
                        <div className = 'headerIcons'>
                            <IconButton color="inherit">
                                <SettingsIcon />
                            </IconButton>
                            <IconButton edge="end" color="inherit" onClick = {this.props.logoutUser}>
                                <AccountCircleRoundedIcon />
                            </IconButton>
                        </div>
                    </Toolbar>
                </AppBar>
            </div>
        );
    }
}
 
export default HeaderArea;