import React from 'react';
import Button from '@material-ui/core/Button';
import { Formik } from 'formik';
import Card from '@material-ui/core/Card';
import Link from '@material-ui/core/Link';
import TextField from '@material-ui/core/TextField';
import Typography from '@material-ui/core/Typography';
import { makeStyles } from '@material-ui/core/styles';
import * as Yup from 'yup';
import registerUser from '../../services/registerUser';
import makeToast from '../NotificationToast/main';
import './main.css';

const useStyles = makeStyles(theme => ({
    root: {
        position: 'fixed',
        height: '100vh',
        width: '100vw',
        top: '0px',
        left: '0px',
        display: 'flex',
        flexDirection: 'column',
        alignItems: 'center',
        backgroundColor:'#dde2eb'
    },
    card: {
        marginTop: theme.spacing(10),
        paddingTop: theme.spacing(2),
        paddingBottom: theme.spacing(2),
        width: '50%',
        display: 'flex',
        flexDirection: 'column',
        justifyContent: 'center',
        alignItems: 'center',
    },
    form: {
        width: '80%',
        marginTop: theme.spacing(2),
    },
    submit: {
        margin: theme.spacing(3, 0, 2),
    },
}));

const Register = props => {
    const classes = useStyles();

    return (
        <div className={classes.root}>
                <Card className={classes.card} variant="outlined">
                    <Typography component="h1" variant="h5" align="center">
                            Register
                    </Typography>
                    <Formik
                        initialValues={{
                            username: '',
                            email: '',
                            password: '',
                        }}
                        validationSchema={Yup.object().shape({
                            username: Yup.string()
                                .required('Username is required')
                                .max(40, 'Username is too long'),
                            email: Yup.string()
                            .required('Username is required')
                            .email('Invalid email address'),
                            password: Yup.string()
                                .required('Password is required')
                                .max(100, 'Password is too long')
                                .min(6, 'Password too short'),
                        })}
                        onSubmit={ async ({ username, email, password }) => {
                            const status = await registerUser(username, email, password);
                            if(status === 200) {
                                makeToast("success", "Registration successful");
                                props.history.push('/');
                            }
                            else
                                makeToast("error", "Username already taken");
                        }}
                    >
                        {({
                            handleSubmit,
                            handleChange,
                            values,
                            touched,
                            errors,
                        }) => (
                            <form
                                onSubmit={handleSubmit}
                                className={classes.form}
                            >
                                <TextField
                                    id="username"
                                    className={classes.textField}
                                    name="username"
                                    label="Username"
                                    fullWidth={true}
                                    variant="outlined"
                                    margin="normal"
                                    required={true}
                                    helperText={
                                        touched.username ? errors.username : ''
                                    }
                                    error={
                                        touched.username &&
                                        Boolean(errors.username)
                                    }
                                    value={values.username}
                                    onChange={handleChange}
                                />
                                <TextField
                                    id="email"
                                    className={classes.textField}
                                    name="email"
                                    label="Email ID"
                                    fullWidth={true}
                                    variant="outlined"
                                    margin="normal"
                                    required={true}
                                    helperText={
                                        touched.email ? errors.email : ''
                                    }
                                    error={
                                        touched.email &&
                                        Boolean(errors.email)
                                    }
                                    value={values.email}
                                    onChange={handleChange}
                                    type="email"
                                />
                                <TextField
                                    id="password"
                                    className={classes.textField}
                                    name="password"
                                    label="Password"
                                    fullWidth={true}
                                    variant="outlined"
                                    margin="normal"
                                    required={true}
                                    helperText={
                                        touched.password ? errors.password : ''
                                    }
                                    error={
                                        touched.password &&
                                        Boolean(errors.password)
                                    }
                                    value={values.password}
                                    onChange={handleChange}
                                    type="password"
                                />
                                <Button
                                    type="submit"
                                    fullWidth={true}
                                    variant="contained"
                                    color="primary"
                                    className={classes.submit}
                                >
                                    Register
                                </Button>
                            </form>
                        )}
                    </Formik>
                    <Typography>
                        <Link
                            onClick={() => props.history.push('/')}
                            href="#"
                        >
                            Already have an account?
                        </Link>
                    </Typography>
                </Card>    
        </div>
    );
};

export default Register;