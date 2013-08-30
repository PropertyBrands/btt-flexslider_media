(function($){

  Drupal.behaviors.fsmInitialize = {
    attach: function(context, settings) {
      if(typeof settings.flexslider_media == 'undefined') {
        return;
      }

      var sliderSelector = '.' + settings.flexslider_media.containerClass + ' .slider';
      var controlsSelector = '.' + settings.flexslider_media.containerClass + ' .controls';
      if(settings.flexslider_media.useFlexControls) {

        // The slider being synced must be initialized first
        $(controlsSelector, context).flexslider({
          animation: 'slide',
          controlNav: false,
          animationLoop: false,
          slideshow: false,
          smoothHeight: true,
          itemWidth: settings.flexslider_media.itemWidth,
          asNavFor: sliderSelector
        });

      }
      $(sliderSelector, context).flexslider({
        controlNav: false,
        animationLoop: false,
        slideshow: false,
        sync: settings.flexslider_media.sync,
        smoothHeight: true
      });
    }

    
  }



})(jQuery);


