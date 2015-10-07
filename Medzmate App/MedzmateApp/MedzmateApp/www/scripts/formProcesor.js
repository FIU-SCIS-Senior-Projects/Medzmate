function navigateToLoadingDeck() {
    window.location = "loadingDeckSelector.html";
}

function populate(frm, id) {
    //populate data from saved file
    var jobj = window.localStorage.getItem(id);
    if (jobj != null)
    {
        var jsonOB = JSON.parse(jobj);
        var test = JSON.stringify(jsonOB, null, 4);

        $.each(jsonOB, function () {
            $('input[name =' + this['name']+']').val(this['value']);
            $('textarea[name =' + this['name'] + ']').val(this['value']); //set systoms and effects
            $('input[name =' + this['name'] + ']').attr("checked", true); //set frequency values and link with other containers
            if (this['name'] == 'Number_of_Doses')
            {
                $("#" + this['name']).val(this['value']);
            }
            
        });

    }
    
}

function saveDataToFile(strawID, jsonData) {
    window.localStorage.setItem(strawID, jsonData);
}

function onSubmitClick()
{
    var strawID = document.getElementById('Straw_id').value;
    var schedule = window.localStorage.getItem("temp");
    saveDataToFile(strawID, schedule);
    navigateToLoadingDeck();
}

function setconfrimationText(jobj)
{
    var test = "";
    $('#eldato').empty();
    $.each(jobj, function () {
        var s = this['name'].replace(/\_/g, ' ');
        $('#eldato').append('<p>' + s + ": " + this['value'] + '</p>');
    });
}

function initialize()
{
    var strawID = window.localStorage.getItem("currentStraw");
    document.getElementById('Straw_id').value = strawID;

    var thisForm = document.getElementById('form_1050292');    

    thisForm.addEventListener('submit', function (event)
                                            {
                                                event.preventDefault();
                                                var jobj = $(this).serializeArray();
                                                var tempSchedule = JSON.stringify(jobj);
                                                saveDataToFile("temp", tempSchedule); // save the form to a temp location 
                                                setconfrimationText(jobj);
                                                $('#confirmDialog').popup("open");
                                                console.log("called popup");
                                            }
    );

    populate(thisForm, strawID);

}

