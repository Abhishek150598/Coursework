const router = require("express").Router();
const {login} = require("./controllers/login");
const {register} = require("./controllers/register");
const {getContacts} = require("./controllers/getContacts");
const {getMessages} = require("./controllers/getMessages");
const {getUsers} = require("./controllers/getUsers");
const {authorisation} = require("./controllers/authorisation");

router.post("/login", login);
router.post("/register", register);
router.get("/getContacts", authorisation, getContacts);
router.get("/getMessages", authorisation, getMessages);
router.get("/getUsers", authorisation, getUsers);

module.exports = router;