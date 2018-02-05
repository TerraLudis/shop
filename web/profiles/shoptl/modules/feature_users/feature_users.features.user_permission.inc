<?php
/**
 * @file
 * feature_users.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feature_users_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'assign Awaiting validation role'.
  $permissions['assign Awaiting validation role'] = array(
    'name' => 'assign Awaiting validation role',
    'roles' => array(),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign Orders Manager role'.
  $permissions['assign Orders Manager role'] = array(
    'name' => 'assign Orders Manager role',
    'roles' => array(
      'Shop Admin' => 'Shop Admin',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign Shop Admin role'.
  $permissions['assign Shop Admin role'] = array(
    'name' => 'assign Shop Admin role',
    'roles' => array(
      'Shop Admin' => 'Shop Admin',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign all roles'.
  $permissions['assign all roles'] = array(
    'name' => 'assign all roles',
    'roles' => array(),
    'module' => 'role_delegation',
  );

  return $permissions;
}
