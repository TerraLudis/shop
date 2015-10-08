<?php
/**
 * @file
 * feature_shop_commons.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function feature_shop_commons_default_rules_configuration() {
  $items = array();
  $items['rules_ensure_stock_is_positive_on_cart_checkout'] = entity_import('rules_config', '{ "rules_ensure_stock_is_positive_on_cart_checkout" : {
      "LABEL" : "Ensure stock is positive on cart\\/checkout",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "commerce_stock", "rules" ],
      "ON" : {
        "commerce_stock_check_product_checkout" : [],
        "commerce_stock_add_to_cart_check_product" : []
      },
      "IF" : [
        { "commerce_stock_order_has_out_of_stock" : { "order" : [ "site:current-cart-order" ] } }
      ],
      "DO" : [ { "redirect" : { "url" : "\\/cart" } } ]
    }
  }');
  $items['rules_out_of_stock'] = entity_import('rules_config', '{ "rules_out_of_stock" : {
      "LABEL" : "Out of stock alert on add to cart form submit",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "commerce_stock" ],
      "ON" : { "commerce_stock_check_add_to_cart_form_state" : [] },
      "IF" : [
        { "data_is" : { "data" : [ "commerce-product:commerce-stock" ], "value" : "0" } }
      ],
      "DO" : [
        { "commerce_stock_set_add_to_cart_form_state" : { "disabled" : "1", "text" : "Hors stock", "class_name" : "out-of-stock" } }
      ]
    }
  }');
  $items['rules_stock_alert'] = entity_import('rules_config', '{ "rules_stock_alert" : {
      "LABEL" : "Stock alert on add to cart form submit",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "commerce_stock" ],
      "ON" : { "commerce_stock_check_add_to_cart_form_state" : [] },
      "IF" : [
        { "data_is" : {
            "data" : [ "commerce-product:commerce-stock" ],
            "op" : "\\u003E",
            "value" : "1"
          }
        },
        { "data_is" : {
            "data" : [ "commerce-product:commerce-stock" ],
            "op" : "\\u003C",
            "value" : "6"
          }
        }
      ],
      "DO" : [
        { "commerce_stock_set_add_to_cart_form_state" : {
            "disabled" : "0",
            "text" : "Acheter l\\u0027un des [commerce-product:commerce-stock-int] restants",
            "class_name" : "in-stock"
          }
        }
      ]
    }
  }');
  $items['rules_stock_last'] = entity_import('rules_config', '{ "rules_stock_last" : {
      "LABEL" : "Stock alert last available on add to cart form submit",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "commerce_stock" ],
      "ON" : { "commerce_stock_check_add_to_cart_form_state" : [] },
      "IF" : [
        { "data_is" : { "data" : [ "commerce-product:commerce-stock" ], "value" : "1" } }
      ],
      "DO" : [
        { "commerce_stock_set_add_to_cart_form_state" : {
            "disabled" : "0",
            "text" : "Acheter le dernier",
            "class_name" : "in-stock"
          }
        }
      ]
    }
  }');
  return $items;
}
