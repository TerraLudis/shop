<?php
/**
 * @file
 * feature_shop_commons.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function feature_shop_commons_user_default_roles() {
  $roles = array();

  // Exported role: Orders Manager.
  $roles['Orders Manager'] = array(
    'name' => 'Orders Manager',
    'weight' => 3,
    'machine_name' => 'orders_manager',
  );

  // Exported role: Shop Admin.
  $roles['Shop Admin'] = array(
    'name' => 'Shop Admin',
    'weight' => 4,
    'machine_name' => 'shop_admin',
  );

  return $roles;
}
