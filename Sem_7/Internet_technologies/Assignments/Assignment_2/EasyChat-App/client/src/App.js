import React, { Component } from 'react';
import { BrowserRouter, Switch, Route } from 'react-router-dom';
import { ThemeProvider }  from '@material-ui/core/styles';
import ChatPage from './pages/ChatPage/main';
import LoginPage from './pages/LoginPage/main';
import RegisterPage from './pages/RegisterPage/main';
import theme from './theme';

class App extends Component {
  
  render() {
    return (
        <ThemeProvider theme={theme}>
          <BrowserRouter>
            <Switch>
              <Route 
                path = "/app" 
                component = {ChatPage}
                exact
              />
              <Route path = "/"
                component = {LoginPage}
                exact
              />
              <Route 
                path = "/register" 
                component = {RegisterPage}
                exact
              />
            </Switch>
          </BrowserRouter>
        </ThemeProvider> 
    );
  }
  
}

export default App;
