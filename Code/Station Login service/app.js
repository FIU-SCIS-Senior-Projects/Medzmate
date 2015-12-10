
var http = require('http');
var util = require('util');
var path = require('path');
var qs = require('querystring');

var spawn = require('child_process').spawn;
var pid = 0;
var med;


http.createServer(function (req, res) {

    console.log('Request received: ');
   // util.log(util.inspect(req)) // this line helps you inspect the request so you can see whether the data is in the url (GET) or the req body (POST)
    util.log('Request recieved: \nmethod: ' + req.method + '\nurl: ' + req.url) // this line logs just the method and url
    var body = "";
    req.on('data', function (chunk) {
        console.log('GOT DATA!');
        body +=chunk;
    });
    req.on('end', function(){
    	var post = qs.parse(body);
	    if (req.url == "/login")
	    {
	    	console.log("Yahoooooooooooooo"+req.url); 
	    	validateLogin(res,post.username,post.password)

	    }
	    else if (req.url == "/saveStraw")
	    {
	    	writeToFile(post.fileName, post.strawSch);	    	
	    	console.log("Starting Medzmate Process from web server ..."); 
	    	/*var exec = require('child_process').exec;
	    	exec(cmd, function(error, stdout, stderr){
					console.log(stdout); 
					console.log(stderr); 
	    	});*/
    		if(med){
    			// kill it before starts
    			med.kill();
    		}
	    	med = spawn('./MedzmateProcess', [], { stdio: 'inherit', detached: false});
	    	/*med.stdout.on('data', function(data){
	    		console.log('' + data);
	    	});
	    	med.stderr.on('data', function(data){
	    		console.log('error: ' + data);
	    	});
	    	med.on('error', function(err){
	    		console.log(err);
	    	});*/
		    res.end('Posted Successfully');
	    }  
	    else if (req.url == "/saveSettings")
	    {
	    	writeToFile("medzmate_config.json", post.strawSch);	    	
	    	console.log("Starting Medzmate Process from web server ..."); 
	    	/*var exec = require('child_process').exec;
	    	exec(cmd, function(error, stdout, stderr){
					console.log(stdout); 
					console.log(stderr); 
	    	});*/
    		if(med){
    			// kill it before starts
    			med.kill();
    		}
	    	med = spawn('./MedzmateProcess', [], { stdio: 'inherit', detached: false});
	    	/*med.stdout.on('data', function(data){
	    		console.log('' + data);
	    	});
	    	med.stderr.on('data', function(data){
	    		console.log('error: ' + data);
	    	});
	    	med.on('error', function(err){
	    		console.log(err);
	    	});*/
		    res.end('Posted Successfully');
	    }  
	        else if (req.url == "/savePatient")
	    {
	    	writeToFile("patient_information.json", post.strawSch);	    	
	    	console.log("Starting Medzmate Process from web server ..."); 
	    	/*var exec = require('child_process').exec;
	    	exec(cmd, function(error, stdout, stderr){
					console.log(stdout); 
					console.log(stderr); 
	    	});*/
    		if(med){
    			// kill it before starts
    			med.kill();
    		}
	    	med = spawn('./MedzmateProcess', [], { stdio: 'inherit', detached: false});
	    	/*med.stdout.on('data', function(data){
	    		console.log('' + data);
	    	});
	    	med.stderr.on('data', function(data){
	    		console.log('error: ' + data);
	    	});
	    	med.on('error', function(err){
	    		console.log(err);
	    	});*/
		    res.end('Posted Successfully');
	    }  
    
    	//res.writeHead(200, { 'Content-Type': 'text/plain' });
    	
    	//console.log('POSTed: ' , body);
    	

    })

}).listen(3080);

function validateLogin(res,user,pass){
	if (user=='Pedro' && pass == 'werty') //"username=pedro&password=werty")
    	{    		
    		res.end('OK loged');
    	}
    	else
    		res.end('Fail login');
	//return true; //only if valid user/password
}

function writeToFile(fileName, data)
{
	var fs = require('fs');
	fs.writeFile(path.join(__dirname,"Documents/"+fileName), data, function(err) {
	    if(err) {
	    	console.log(__dirname);
	        return console.log(err);
	    }

	    console.log("The file was saved!");
	    return true;
	}); 
}


console.log('Server started');
