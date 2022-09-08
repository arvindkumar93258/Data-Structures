const express = require('express');
const app  = express();
const path = require('path');
const hbs = require('hbs');


require("./src/db/mongodb");

const PORT = process.env.PORT || 3000;

// const static_path = path.join(__dirname, "/public/");
// app.use(express.static(static_path));

// app.get('/', (req, res)=>
// {
//     res.send("Hello world from server.js");
// })

const template_path = path.join(__dirname, "/templates/views");
const partial_path = path.join(__dirname, "/templates/partials");

app.set("view engine", "hbs");
app.set("views", template_path);
hbs.registerPartials(partial_path);



app.get('/', (req, res)=>{
    res.render("index")
})




app.listen(PORT, ()=>{
    console.log(`Server is running on http://localhost:${PORT}`);
})
