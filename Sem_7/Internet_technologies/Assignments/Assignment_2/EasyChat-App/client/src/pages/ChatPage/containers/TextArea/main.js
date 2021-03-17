import React, { Component } from 'react';
import AppBar from '@material-ui/core/AppBar';
import Toolbar from '@material-ui/core/Toolbar';
import IconButton from '@material-ui/core/IconButton';
import SendIcon from '@material-ui/icons/Send';
import AttachFileIcon from '@material-ui/icons/AttachFile';
import TextField from '@material-ui/core/TextField';
import './main.css';

class TextArea extends Component {
    state = {
        textFieldValue: ''
    }

    onClickHandler = async () => {
        const { textFieldValue } = this.state;
        if(textFieldValue !== '')
            await this.props.sendMessage(textFieldValue);
        console.log("Message sent");
        this.setState({textFieldValue: ''});
    }
    render() { 
        return (
            <div className = 'textArea'>
                <AppBar position="static" color="secondary">
                    <Toolbar>
                        <IconButton color="inherit">
                            <AttachFileIcon />
                        </IconButton>
                        <TextField className = "text" 
                            id="full-width-text-field"
                            label="Type your message here"
                            variant="outlined"
                            size="small"
                            fullWidth
                            value={this.state.textFieldValue}
                            onChange={(event) => this.setState({
                                textFieldValue: event.target.value
                            })}
                        />
                        
                        <IconButton edge="end" color="inherit" onClick= {this.onClickHandler}>
                            <SendIcon />
                        </IconButton>
                    </Toolbar>
                </AppBar>
            </div>
        );
    }
}
 
export default TextArea;