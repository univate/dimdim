$(document).ready(function() {
  dimdimRecordingBindButtons($(this));
});

dimdimRecordingBindButtons = function(elem) {
  $('a.dimdim-recording-link').click(function() {
    var options = {
      url : '/dimdim/js' + $(this).attr('href'),
      draggable : false,
      width : 640,
      height : 150,
      onSubmit : function() {}
    }
    Drupal.modalFrame.open(options);
    return false;
  });
}


