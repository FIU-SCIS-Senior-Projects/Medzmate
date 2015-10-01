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
            console.log(this['name'] + " " + this['value']);
            $('input[name =' + this['name']+']').val(this['value']);
            $('textarea[name =' + this['name'] + ']').val(this['value']); //set systoms and effects
            $('input[name =' + this['name'] + ']').attr("checked", true); //set frequency values and link with other containers
            if (this['name'] == 'nDoses')
            {
                $('#'+this['name'] +' option[value=' + this['value'] + ']').attr('selected', 'selected');
            }
            
        });

       // $("#form_1050292").addClass("ui-state-disabled");
       // $("input").addClass("ui-state-disabled");
        //$("textarea").addClass("ui-state-disabled");

    }
    
}

function saveDataToFile(strawID, jsonData) {
    window.localStorage.setItem(strawID, jsonData);
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
                                                var test = JSON.stringify(jobj);
                                                saveDataToFile(strawID, test);
                                                //alert(test);
                                                navigateToLoadingDeck();
                                            }
    );

    populate(thisForm, strawID);

}

