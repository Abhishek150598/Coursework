import axios from 'axios';

const registerUser = (username, email, password) => {
    return axios.post("http://localhost:8000/apis/register", {
        username,
        email,
        password,
    })
    .then((response) => {
        console.log(response.data);
        return response.status;
    })
    .catch((err) => {
        console.log(err);
        return err.response.status;
    });
}

export default registerUser;