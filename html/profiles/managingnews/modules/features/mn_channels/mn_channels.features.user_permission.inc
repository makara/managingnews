<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function mn_channels_user_default_permissions() {
  $permissions = array();

  // Exported permission: create channel content
  $permissions['create channel content'] = array(
    'name' => 'create channel content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: delete any channel content
  $permissions['delete any channel content'] = array(
    'name' => 'delete any channel content',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: delete own channel content
  $permissions['delete own channel content'] = array(
    'name' => 'delete own channel content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: edit any channel content
  $permissions['edit any channel content'] = array(
    'name' => 'edit any channel content',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: edit own channel content
  $permissions['edit own channel content'] = array(
    'name' => 'edit own channel content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  return $permissions;
}
