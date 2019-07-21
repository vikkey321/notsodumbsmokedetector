'use strict'

var express = require('express');
var bodyParser = require('body-parser');
var request = require("request");
var cors = require('cors');

var app = express();

app.use(bodyParser());
app.use(bodyParser.json()); 
app.use(cors());


app.get('/test', function(req, res) {
	res.setHeader('Content-Type', 'application/json');
	res.send(JSON.stringify({"Message" : "Running Succesfully..!!"}));
});

app.get('/reset', function(req, res) {
    var options = { 
        method: 'GET',
        url: 'http://192.168.0.102/D0/0', //IP address of your nodemcu
        headers: 
        { 
            'cache-control': 'no-cache' 
        } 
    };

    request(options, function (error, response, body) {
        if (error) throw new Error(error);
        console.log(body);
        res.setHeader('Content-Type','application/json');
        res.send(JSON.stringify({"Message" : "Running Succesfully...!!"}));
    });
});

app.listen(3000);
console.log('Listening on port 3000...');