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
  $items['commerce_cart_expiration_delete_expired_carts_custom'] = entity_import('rules_config', '{ "commerce_cart_expiration_delete_expired_carts_custom" : {
      "LABEL" : "Delete expired carts (custom)",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "commerce_cart_expiration" ],
      "ON" : { "commerce_cart_expiration_cron" : [] },
      "DO" : [
        { "commerce_cart_expiration_delete_orders" : { "interval" : 3600, "limit" : "100" } }
      ]
    }
  }');
  return $items;
}
