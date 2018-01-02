<?php
/**
 * @file
 * feature_events.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feature_events_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create commerce_product entities of bundle ticket'.
  $permissions['create commerce_product entities of bundle ticket'] = array(
    'name' => 'create commerce_product entities of bundle ticket',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  // Exported permission: 'create event content'.
  $permissions['create event content'] = array(
    'name' => 'create event content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create ticket content'.
  $permissions['create ticket content'] = array(
    'name' => 'create ticket content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any event content'.
  $permissions['delete any event content'] = array(
    'name' => 'delete any event content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any ticket content'.
  $permissions['delete any ticket content'] = array(
    'name' => 'delete any ticket content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own event content'.
  $permissions['delete own event content'] = array(
    'name' => 'delete own event content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own ticket content'.
  $permissions['delete own ticket content'] = array(
    'name' => 'delete own ticket content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any commerce_product entity of bundle ticket'.
  $permissions['edit any commerce_product entity of bundle ticket'] = array(
    'name' => 'edit any commerce_product entity of bundle ticket',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit any event content'.
  $permissions['edit any event content'] = array(
    'name' => 'edit any event content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any ticket content'.
  $permissions['edit any ticket content'] = array(
    'name' => 'edit any ticket content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own commerce_product entities of bundle ticket'.
  $permissions['edit own commerce_product entities of bundle ticket'] = array(
    'name' => 'edit own commerce_product entities of bundle ticket',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit own event content'.
  $permissions['edit own event content'] = array(
    'name' => 'edit own event content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own ticket content'.
  $permissions['edit own ticket content'] = array(
    'name' => 'edit own ticket content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'view any commerce_product entity of bundle ticket'.
  $permissions['view any commerce_product entity of bundle ticket'] = array(
    'name' => 'view any commerce_product entity of bundle ticket',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view own commerce_product entities of bundle ticket'.
  $permissions['view own commerce_product entities of bundle ticket'] = array(
    'name' => 'view own commerce_product entities of bundle ticket',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  return $permissions;
}
