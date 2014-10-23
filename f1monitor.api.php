<?php


/**
 * Implement hook_ctools_plugin_directory().
 * Tell the plugin system where your plugins are.
 */
function f1monitor_ctools_plugin_directory($module, $plugin_type) {
  if ($module == 'f1monitor') {
    return "plugins/$plugin_type";
  }
}


/**
 * Example plugin
 *
 * If this looks familiar, it is. The plugin definition only has a single value for a callback.
 * The callback itself mirrors the values returned by hook_requirements().
 */

$plugin = array(
  'callback' => 'f1monitor_caching_is_on'
);

/**
 * @see https://api.drupal.org/api/drupal/modules%21system%21system.api.php/function/hook_requirements/7
 * @return Array
 *   The return value uses all the same key/value pairs as hook_requirements, with the addition of the following
 *   - show status: Determines of this plugin's output will be displayed on the default status page as well. Defaults to
 *     false.
 */
function f1monitor_caching_is_on() {
  $cache = variable_get('cache', false);

  $pos_desciption = t('Caching for anonymous users is enabled.');
  $neg_description = t('Caching for anonymous users is disabled.');

  $requirement = array(
    'title' => t('Cache pages for Anonymous users.'),
    'value' => t('Enabled'),
    'description' => $cache ? $pos_desciption : $neg_description,
    'severity' => $cache ? REQUIREMENT_OK : REQUIREMENT_WARNING,
    'show status' => TRUE,
  );

  return array(
    'f1monitor_caching' => $requirement,
  );
}


