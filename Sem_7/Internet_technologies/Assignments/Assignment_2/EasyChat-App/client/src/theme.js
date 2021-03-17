import { createMuiTheme } from '@material-ui/core/styles';

const theme = createMuiTheme({
  palette: {
    primary: {
      main: '#5254a3',
    },
    secondary: {
      main: "#6467bd",
    },
  },
  typography: {
    button: {
      textTransform: 'none'
    }
  }
});

export default theme;
