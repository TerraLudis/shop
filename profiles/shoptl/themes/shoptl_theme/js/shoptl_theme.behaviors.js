(function ($, Drupal, document) {

  "use strict";

  /**
   * Update cart title to include total quantity and allow to click the title to
   * go to the cart page.
   */
  Drupal.behaviors.CartHeading = {
    attach: function(context, settings) {
      $('#block-commerce-cart-cart', context).once('cart-heading', function() {
        var $target = $(this).find('.line-item-summary-view-cart a');
        var $title = $(this).find('h2');
        var count = $(this).find('.line-item-quantity-raw').text();
        if (count) {
          $title.text($title.text() + ' (' + count + ')')
        }
        $title.bind('click', function() {
          document.location = $target.attr('href');
        });
      });
    }
  };

})(jQuery, Drupal, document);
