require("dotenv").config();

// App setup
const express = require('express');

const app = express();
const server = app.listen(8000, function(){
    console.log("Server started at port 8000");
});

// Body parser middleware
const bodyParser = require("body-parser");
app.use(
  bodyParser.urlencoded({
    extended: false,
  })
);
app.use(bodyParser.json());
app.use(require("cors")());

//Models setup
require('./models/User');
require('./models/Message');
require('./models/BroadcastMessage');
// Mongoose setup
const mongoose = require("mongoose");

mongoose.connect(process.env.DATABASE, {
  useUnifiedTopology: true,
  useNewUrlParser: true,
});

mongoose.connection.on("error", (err) => {
  console.log("Mongoose Connection ERROR: " + err.message);
});

mongoose.connection.once("open", () => {
  console.log("MongoDB Connected!");
});

// Routes setup
app.use("/apis", require("./routes"));

// Socket setup
const {handleSocket} = require("./handleSocket");
handleSocket(server);



