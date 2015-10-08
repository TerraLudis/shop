<?php
/**
 * @file
 * feature_site_contexts.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_site_contexts_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
