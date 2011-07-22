/**
 * Fullsceen Behavior
 *
 * @param event
 *   Event Object
 */
OL.Behaviors.semi_fullscreen = function(event) {
  var mapDef = event.mapDef;
  var mapid = mapDef.id;
  var $map = $('#' + mapid);
  var $mapControls = $('#openlayers-controls-' + mapid);
  
  $('<a href="#"></a>')
    .attr('id', 'openlayers-controls-semi_fullscreen-' + mapid)
    .addClass('openlayers-controls-semi_fullscreen')
    .data('mapid', mapid)
    .appendTo('#openlayers-controls-' + mapid)
    .click(function() {
      var $thisElement = $(this);
    
      // Store data
      if (!OL.isSet(OL.Behaviors.semi_fullscreenRegistry)) {
        OL.Behaviors.semi_fullscreenRegistry = [];
      }
      if (!OL.isSet(OL.Behaviors.semi_fullscreenRegistry[mapid])) {
        OL.Behaviors.semi_fullscreenRegistry[mapid] = {};
        OL.Behaviors.semi_fullscreenRegistry[mapid].semi_fullscreen = false;
        OL.Behaviors.semi_fullscreenRegistry[mapid].mapstyle = [];
        OL.Behaviors.semi_fullscreenRegistry[mapid].controlsstyle = [];
      }
      
      // Check if semi_fullscreen
      if (!OL.Behaviors.semi_fullscreenRegistry[mapid].semi_fullscreen) {
        OL.Behaviors.semi_fullscreenRegistry[mapid].semi_fullscreen = true;
      
        // Store old css values
        var mapStylesToStore = ['position','top','left','right','width','height','z-index'];
        var controlStylesToStore = ['position','top','right'];
        for (var ms in mapStylesToStore) {
          OL.Behaviors.semi_fullscreenRegistry[mapid].mapstyle[mapStylesToStore[ms]] = $('#' + mapid).css(mapStylesToStore[ms]);
        }
        for (var cs in controlStylesToStore) {
          OL.Behaviors.semi_fullscreenRegistry[mapid].controlsstyle[controlStylesToStore[cs]] = $('#openlayers-controls-' + mapid).css(controlStylesToStore[cs]);
        }
      
        // Resize the map.
        $map.css('position','fixed')
          .css('top','50px')
          .css('left','0px')
          .css('right','0px')
          .css('height','auto')
          .css('bottom','0px')
          .css('background','#fff')
          .css('z-index','999');
        // Change CSS on map controls
        $mapControls.css('position','fixed')
          .css('top','60px')
          .css('right','0px');
        // Update classes
        $thisElement.removeClass('openlayers-controls-semi_fullscreen')
          .addClass('openlayers-controls-unsemi_fullscreen');
        
        // Update size of OpenLayers
        event.map.updateSize();
      }
      else {
        // Restore styles, resizing the map.
        for (var ms in OL.Behaviors.semi_fullscreenRegistry[mapid].mapstyle) {
          $('#' + mapid).css(ms,OL.Behaviors.semi_fullscreenRegistry[mapid].mapstyle[ms]);
        };
        for (var cs in OL.Behaviors.semi_fullscreenRegistry[mapid].controlsstyle) {
          $('#openlayers-controls-' + mapid).css(cs,OL.Behaviors.semi_fullscreenRegistry[mapid].controlsstyle[cs]);
        };
        
        // Update classes
        $thisElement.removeClass('openlayers-controls-unsemi_fullscreen')
          .addClass('openlayers-controls-semi_fullscreen');
          
        // Update stored registry and OpenLayers map size
        OL.Behaviors.semi_fullscreenRegistry[mapid].semi_fullscreen = false;
        event.map.updateSize();
      }
    });
}


