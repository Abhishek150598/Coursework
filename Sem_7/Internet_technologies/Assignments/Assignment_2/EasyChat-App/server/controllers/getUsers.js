const mongoose = require("mongoose");
const User = mongoose.model("User");

exports.getUsers = async (req, res) => {
    try {
        const users = await User.find({}).select('username');

        res.json({
            users,
        })
    
    } catch(err) {
        console.log(err);
        res.status(400).json({
            message: err,
        });
    }
    
};