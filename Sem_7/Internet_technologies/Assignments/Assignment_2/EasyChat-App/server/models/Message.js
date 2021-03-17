const mongoose = require("mongoose");

const messageSchema = new mongoose.Schema(
  {
    to: {
        type: String,
        required: true,
    },
    from: {
        type: String,
        required: true,
    },
    body: {
        type: String,
        required: true,
    },
  }, {
    timestamps: true
  }
);

module.exports = mongoose.model("Message", messageSchema);