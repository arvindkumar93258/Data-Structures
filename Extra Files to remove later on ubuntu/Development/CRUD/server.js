
const dotenv = require('dotenv');
const express = require('express');
const morgan = require('morgan');
const bodyparser = require('body-parser');
const path = require('path');



const app = express();

//impoering the config file for use
dotenv.config({path: 'config.env'});

//port on which server will be running
const PORT = process.env.PORT || 3000;

//to display the log message in the console
app.use(morgan('tiny'));

//parse request to body-parser
app.use(bodyparser.urlencoded({extended: true}));

//set view engine
app.set("view engine", "ejs");//here you can set engine as html or pug or others

//load assets files
app.use('/css', express.static(path.resolve(__dirname, "assets/css")));
//if you want to include the style.css file the you can do like bwlow
//app.use('/css/style.css', express.static(path.resolve(__dirname, assets/css)));
app.use('/img', express.static(path.resolve(__dirname, "assets/img")));
app.use('/js', express.static(path.resolve(__dirname, "assets/js")));

app.get('/', (req, res)=>{
    res.send('CRUD operations');
});


app.listen(PORT, ()=>{console.log(`Server is running on http://localhost:${PORT}`)});


