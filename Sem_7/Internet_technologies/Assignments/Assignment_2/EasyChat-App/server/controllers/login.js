const mongoose = require("mongoose");
const User = mongoose.model("User");
const jwt = require("jwt-then");
const sha256 = require("sha256");

exports.login = async (req, res) => {
    try {
        const { username, password } = req.body;
        const user = await User.findOne({
            username,
            password: sha256.x2(password),
        });
    
        if (!user) 
            throw "Incorrect username or password";
    
        const token = await jwt.sign({ username: user.username }, process.env.SECRET);
    
        res.json({
            message: "User logged in successfully!",
            token,
        });
    } catch(err) {
        console.log(err);
        res.status(400).json({
            message: err,
        });
    }
};