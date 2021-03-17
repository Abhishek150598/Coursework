import axios from 'axios';

const loginUser = (username, password) => {
    return axios.post("http://localhost:8000/apis/login", {
            username,
            password,
    }).then((response) => {
        sessionStorage.setItem("AuthToken", response.data.token);
        sessionStorage.setItem("User", username);
        console.log(response.data);
        return response.status;
    }).catch((err) => {
        console.log(err.response.data.message);
        return err.response.status;
    });
    
    
};

export default loginUser;