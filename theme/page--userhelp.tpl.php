<?php
/**
 * @file
 * Theme implementation to display a pop-up help page.
 *
 * Copy this file to the active themes '/templates' folder
 */
?>

  <div id="userhelp-wrapper">

    <div<?php print $attributes; ?>>

      <?php if (!empty($messages)): ?>
        <div id="userhelp-messages">
          <?php print $messages; ?>
        </div>
      <?php endif; ?>

      <?php if (isset($page['header'])) : ?>
      <div id="userhelp-header" class="">
        <?php print render($page['header']['header']['branding']); ?>
      </div>
      <?php endif; ?>

      <?php if (isset($page['content'])) : ?>
      <div id="userhelp-content" class="">
        <?php print render($page['content']); ?>
      </div>
      <?php endif; ?>

      <div id="popup-button-close" class="btn-wrapper">
        <button
            id="selid-popup-button-close"
            type="button"
            title="<?php print t('label_close_popup', array(), array('context' => 'netpunkt_userhelp')); ?>"
            class="btn btn-blue">
                <?php print t('label_close_popup', array(), array('context' => 'netpunkt_userhelp')); ?>
        </button>
      </div>

      <?php if (isset($page['footer'])) : ?>
      <div id="userhelp-footer" class="l-footer">
        <?php print render($page['footer']); ?>
      </div>
      <?php endif; ?>

    </div>

  </div>
