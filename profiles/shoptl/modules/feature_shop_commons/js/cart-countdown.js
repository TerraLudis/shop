(function($, Drupal) {

  Drupal.behaviors.CartCountdown = {
    attach: function(context, settings) {
      $('[data-cart-countdown]').once('cart-countdown', function() {
        var date = new Date($(this).data('cart-countdown') * 1000);
        $(this).find('span')
          .countdown(date, function(event) {
            var format = '%-S seconde%!S';
            if(event.offset.minutes > 0) {
              format = '%-M minute%!M ' + format;
            }
            if(event.offset.hours > 0) {
              format = '%-H heure%!H ' + format;
            }
            $(this).html(event.strftime(format));
          })
          .on('finish.countdown', function(event) {
            $(this).parent()
              .html('Votre panier a expiré !')
              .addClass('disabled')
              .addClass('cart-expired');
            $(this).parents('form').find('.form-actions :input[type="submit"]')
              .attr('disabled', true);
          });
      });
    }
  };

})(jQuery, Drupal);