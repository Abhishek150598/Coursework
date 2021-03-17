const mongoose = require("mongoose");
const User = mongoose.model("User");

exports.getContacts = async (req, res) => {
    try {
        const username = req.payload.username;
        const user = await User.findOne({username});
        if(!user)
            throw "Invalid username";

        res.json({
            message: "Contacts fetching successful",
            contacts: user.contacts,
        })
    
    } catch(err) {
        console.log(err);
        res.status(400).json({
            message: err,
        });
    }
    
};