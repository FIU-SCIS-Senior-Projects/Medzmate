function writeTolog(filename, content, logcallback)
{
    //on success get the file and write the heather
    function onResolveSuccess(dir) {
        console.log(filename + " fileEntry.name ", dir);        
        dir.getFile(filename, { create: true }, function (file) {
            console.log("got the file", file);
            logOb = file;            
            writeLog(logOb, content, logcallback);
        }, fail);

    }      

   // window.resolveLocalFileSystemURL(cordova.file.externalRootDirectory, gotFS, fail); //uncoment to make log work on android
    logcallback(); //comment after uncoment previous line to make log work

    function gotFS(trySystem) {
        trySystem.getDirectory("MedzmateLogs", { create: true }, gotFloder);
    }

    function gotFloder(folder) {
        folder.getDirectory("" + window.localStorage.getItem("currentStation") + "logs", { create: true }, onResolveSuccess);
    }

    // when something go wrong
    function fail(evt) {
        console.log("Error " + evt.code);
        logcallback(false);
    }
}

function writeLog(file, str, logcallback) {
    if (!file)
    {
        console.log("retunrning no file"); return;
    }
    var currentUser = window.localStorage.getItem("currentUser");
    var medzmateId = window.localStorage.getItem("currentStation");
    var log = "\r\n\r\n***************************************\r\n  [Created by user: " + currentUser + " on " + (new Date()) + "]\r\n" + "Medzmate Station Id: " + medzmateId + "\r\n" + str + "\r\n***************************************";
    
    console.log("going to log " + log);
    file.createWriter(function (fileWriter)
    {
        fileWriter.seek(fileWriter.length);

        var blob = new Blob([log], { type: 'text/plain' });
        fileWriter.write(blob);
        alert("Acttion saved to Log");
        console.log("ok, in theory i worked");

        logcallback(true);
    }, fail);

    // when something go wrong
    function fail(evt) {
        console.log("Error " + evt.code);
        logcallback(false);
    }
}

