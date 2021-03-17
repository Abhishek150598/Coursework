import React, { Component } from 'react';
import AppBar from '@material-ui/core/AppBar';
import Toolbar from '@material-ui/core/Toolbar';
import Autocomplete from '@material-ui/lab/Autocomplete';
import TextField from '@material-ui/core/TextField';
import IconButton from '@material-ui/core/IconButton';
import ArrowForwardRoundedIcon from '@material-ui/icons/ArrowForwardRounded';
import './main.css';

class SearchArea extends Component {
    state = {
        textFieldValue: ''
    }

    onClickHandler = () => {
        const { users, updateCurrentContact } = this.props;
        const { textFieldValue } = this.state;
        if(users.map(user => user.username).includes(textFieldValue)) {
            console.log("Yes");
            updateCurrentContact(textFieldValue);
        }
        else {
            console.log("No");
            console.log(textFieldValue);
            
        }
            
    }
    
    render() { 
        const { users } = this.props;
        return (
            <div className = 'searchArea'>
                <AppBar position="static" color = "primary">
                    <Toolbar>    
                        <Autocomplete 
                            className = 'searchBar'
                            freeSolo
                            value={this.state.textFieldValue}
                            onInputChange={
                                (event, value) => {
                                    this.setState({textFieldValue: value})
                                }
                            }
                            options= {users.map(user => user.username)}
                            renderInput={(params) => (
                                <TextField 
                                    {...params} 
                                    className = 'textfield'
                                    
                                    label="Search by username" 
                                    margin="normal" 
                                    variant="outlined" 
                                    size="small"
                                />
                            )}
                        /> 
                        <IconButton edge="end" color="inherit" onClick = {this.onClickHandler}>
                            <ArrowForwardRoundedIcon />
                        </IconButton>
                    </Toolbar>
                </AppBar>
            </div>
        );
    }
}
 
export default SearchArea;