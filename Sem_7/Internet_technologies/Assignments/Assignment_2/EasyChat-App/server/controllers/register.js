const mongoose = require("mongoose");
const User = mongoose.model("User");
const sha256 = require("sha256");

exports.register = async (req, res) => {
    try {
        const { username, email, password } = req.body;

        const userExists = await User.findOne({username});
        if(userExists)
           throw "Username already taken";

        const user = new User({
            username,
            email,
            password: sha256.x2(password),
            contacts: [{name: 'Broadcast Channel', lastMessage: '', unread: 0}],
        });

        await user.save();
        
        res.json({
            message: "User " + username + " registered successfully!",
        });
    } catch(err) {
        console.log(err);
        res.status(400).json({
            message: err,
        });
    }
    
};