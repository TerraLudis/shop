(function($, Drupal) {

  Drupal.behaviors.CartCountdown = {
    attach: function(context, settings) {
      $('[data-cart-countdown]').once('cart-countdown', function() {
        var cartId = $(this).data('cart-id');

        if ($(this).data('cart-countdown') <= Date.now()) {
          Drupal.behaviors.CartCountdown._expire(cartId);
        }
        else {
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
              $(element).parent()
                .html('Votre panier a expiré !')
                .addClass('disabled')
                .addClass('cart-expired');
              $(element).parents('form').find('.form-actions :input[type="submit"]')
                .attr('disabled', true);

              Drupal.behaviors.CartCountdown._expire(cartId);
            });
        }
      });
    },

    _expire: function(cartId) {
      $.ajax({
        url: 'commerce_cart_expiration/expire/' + cartId,
        type: 'GET',
        success: function(response) {
          if (response.status) {
            window.location = 'cart/expired';
          }
        }
      });
    }
  };

})(jQuery, Drupal);