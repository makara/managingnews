<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function mn_core_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer blocks
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: administer dashboards
  $permissions['administer dashboards'] = array(
    'name' => 'administer dashboards',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: administer feeds
  $permissions['administer feeds'] = array(
    'name' => 'administer feeds',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: administer mn
  $permissions['administer mn'] = array(
    'name' => 'administer mn',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: administer permissions
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: administer site configuration
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: administer users
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: change own username
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: clear syndication feeds
  $permissions['clear syndication feeds'] = array(
    'name' => 'clear syndication feeds',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: clear terms feeds
  $permissions['clear terms feeds'] = array(
    'name' => 'clear terms feeds',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: create feed content
  $permissions['create feed content'] = array(
    'name' => 'create feed content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: delete any feed content
  $permissions['delete any feed content'] = array(
    'name' => 'delete any feed content',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: delete own feed content
  $permissions['delete own feed content'] = array(
    'name' => 'delete own feed content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit any feed content
  $permissions['edit any feed content'] = array(
    'name' => 'edit any feed content',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: edit data taxonomy relations
  $permissions['edit data taxonomy relations'] = array(
    'name' => 'edit data taxonomy relations',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: edit own feed content
  $permissions['edit own feed content'] = array(
    'name' => 'edit own feed content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: import opml feeds
  $permissions['import opml feeds'] = array(
    'name' => 'import opml feeds',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: import syndication feeds
  $permissions['import syndication feeds'] = array(
    'name' => 'import syndication feeds',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: import terms feeds
  $permissions['import terms feeds'] = array(
    'name' => 'import terms feeds',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: manage stored views
  $permissions['manage stored views'] = array(
    'name' => 'manage stored views',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: mark items
  $permissions['mark items'] = array(
    'name' => 'mark items',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: view uploaded files
  $permissions['view uploaded files'] = array(
    'name' => 'view uploaded files',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  return $permissions;
}
