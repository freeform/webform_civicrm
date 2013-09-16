<?php

/**
 * @file
 * Admin form inline-help.
 */

/**
 * Class wf_crm_admin_help
 * Adding a static function to this class with the same name as a field will magically add pop-up help for that field to the admin form.
 */
class wf_crm_admin_help {

  static function contact_existing() {
    print '<p>' .
      t('Gives many options for how this contact can be autofilled or selected. From the Webform tab you can edit this field to configure:') .'</p><ul>' .
      '<li>' . t('Widget: Determine whether to expose this field to the form as an autocomplete or select element, or hide it and pick the contact automatically.') . '</li>' .
      '<li>' . t('Default Value: Select a contact based on the current user, relationships, or other options.') . '</li>' .
      '<li>' . t('Filters: Limit the list of available choices from which this contact may be autofilled or selected.') . '</li>' .
      '<li>' . t('Show/Hide Fields: Control which other fields the user is allowed to edit and which will be hidden.') . '</li>' .
      '</ul>';
  }

  static function contact_employer_id() {
    print '<p>' .
      t('Choose a webform contact of type "Organization" to be the employer for this individual.') .
      '</p><p>' .
      t('Use the "Existing Contact" field for that organization to enable autocomplete or select of employers.') .
      '</p><p>' .
      t('Configure the "Existing Contact" default value to be "Employer" relationship to this individual.') .
      '</p>';
  }

  static function contact_image_URL() {
    print '<p>' .
      t('Allows an image to be associated with a contact. This image will appear in CiviCRM, but the file is stored in Drupal. If the webform submission or entire webform were to be deleted, the image would be lost.') .
      '</p>';
  }

  static function contact_contact_id() {
    print '<p>' .
      t('This hidden field can be used to as a token to generate links, for example to include an email link back to this form to update their info.') .
      '</p>';
  }

  static function contact_external_identifier() {
    self::contact_contact_id();
  }

  static function contact_cs() {
    self::contact_contact_id();
  }

  static function address_master_id() {
    print '<p>' .
      t('When selected, will hide fields for this address and use those of the other contact.') .
      '</p><p>' .
      t('Tip: In many use-cases it is desirable to show this field as a single checkbox. You can configure that by editing the field and removing all but one option (the one this contact is allowed to share) and re-labelling it something like "Same as my address".') .
      '</p>';
  }


  static function contribution_contribution_page_id() {
    print '<p>' .
      t("It is recommended to <a !link>create a new contribution page</a> solely for webform use. When configuring the page, most options will be irrelevant (such as profiles, premiums, widgets, etc.). Only the following need to be configured:",
      array('!link' => 'target="_blank" href="' . url('civicrm/admin/contribute/add', array('query' => array('reset' => 1, 'action' => 'add'))) . '"')) .
      '</p><ul>' .
      '<li>' . t('Title: Displayed on the webform.') . '</li>' .
      '<li>' . t('Financial Type: Controls overall contribution type.') . '</li>' .
      '<li>' . t('Currency: Sets currency for all payment fields on this form.') . '</li>' .
      '<li>' . t('Payment Processors: Controls list of options here.') . '</li>' .
      '<li>' . t('Email Receipt: Configure email receipts from this webform.') . '</li>' .
      '</ul>';
  }

  static function contribution_payment_processor_id() {
    print '<p>' .
      t('All payment processors enabled on the contribution page are available here. "Pay Later" option allows the user to purchase events/memberships without entering a credit card.') .
      '</p><p>' .
      t("Note that only on-site credit card processors will work on Webforms. Services that redirect to an external website, such as Paypal Standard, are not supported.") .
      '</p>';
  }

  static function contribution_total_amount() {
    print '<p>' .
      t('If selected, this amount will be in addition to any paid events and memberships.') .
     '</p>';
    self::fee();
  }

  static function participant_fee_amount() {
    print '<p>' .
      t('Price for this event. If multiple events or participants are registered with this field, the amount will be multiplied per-person, per-event.') .
      '</p><p>' .
      t('Note that any event prices you have configured in CiviCRM are not imported into the Webform - you will need to reconfigure them here.') .
     '</p>';
    self::fee();
  }

  static function fee() {
    print '<p>' .
      t('Once added to the webform, this field can be configured in a number of ways by changing its settings.') .
     '</p><strong>' .
     t('Possible Widgets:') .
     '</strong><ul>' .
      '<li>' . t('Number (default): Allow the user to enter an amount, optionally constrained by min, max, and increments.') . '</li>' .
      '<li>' . t('Hidden: Set the amount without giving the user a choice.') . '</li>' .
      '<li>' . t('Select/Radios: Allow the user to choose from one of several options.') . '</li>' .
      '<li>' . t('MultiSelect/Checkboxes: Each choice the user selects will be added together.') . '</li>' .
      '</ul>';
  }

  static function participant_status_id() {
    print '<ul><li>' .
      t('In "Automatic" mode, status will be set to "Registered" (or "Pending" if the user chooses to "Pay Later" for events with a fee). The user will be able to cancel registration by re-visiting the form and de-selecting any events they are registered for.') .
      '</li><li>' .
      t('If a status is selected here, events will be autofilled only if the participant has that status.') .
      '</li><li>' .
      t('If this field is exposed to the webform ("User Select"), events will be autofilled only if the particiant status among the enabled options.') .
      '</li></ul>';
  }

  static function reg_options_show_remaining() {
    print '<p>' .
      t('Display a message at the top of the form for each event with a registration limit or past end date.') .
      '</p>';
  }

  static function reg_options_validate() {
    print '<p>' .
      t('Will not allow the form to be submitted if user registers for an event that is ended or full.') .
      '</p>';
  }

  static function reg_options_block_form() {
    print '<p>' .
      t('Hide webform if all the events for the form are full or ended.') .
      '</p>';
  }

  static function reg_options_show_past_events() {
    print '<p>' .
      t('Upcoming events will always be shown. To also display events that have ended, choose an option for how far in the past to search.') .
      '</p>';
  }

  static function reg_options_title_display() {
    print '<p>' .
      t('Controls how events are displayed. Date formats can be further configured in <a !link>CiviCRM Date Settings</a>',
        array('!link' => 'target="_blank" href="' . url('civicrm/admin/setting/date', array('query' => array('reset' => 1))) . '"')
      ) .
      '</p>';
  }

  static function membership_membership_type_id() {
    print '<p>' .
      t('Fee will be calculated automatically based on selected membership type and number of terms chosen. A contribution page must be enabled to collect fees.') .
     '</p>';
  }

  static function membership_status_id() {
    print '<p>' .
      t('If number of terms is enabled, status can be calculated automatically based on new/renewal status and payment.') .
     '</p>';
  }

  static function membership_num_terms() {
    print '<p>' .
      t('Membership dates will be filled automatically by selecting terms. This can be overridden by entering dates manually.') .
     '</p><p>' .
      t('Note: Number of terms is required to calculate membership fees for paid memberships. Fees will not be charged when dates are entered manually') .
     '</p>';
  }

  static function multiselect_options() {
    print '<p>' .
      t('You may set options here and/or add this element to the webform ("User Select"). If you do both, options set here will be applied automatically and will not appear on the form.') .
      '</p>';
  }

  static function webform_label() {
    print '<p>' .
      t('Labels help you keep track of the role of each contact on the form. For example, you might label Contact 1 "Parent", Contact 2 "Spouse" and Contact 3 "Child".') .
      '</p><p>' .
      t("Labels do not have to be shown to the end-user. By default they will be the title of each contact's fieldset, but you may rename (or remove) fieldsets without affecting this label.") .
      '</p>';
  }

  static function activity_default_subject() {
    print '<p>' .
      t('You can override this default by allowing users to enter a subject (enable "Activity Subject" field below)') .
      '</p>';
  }


  static function activity_target_contact_id() {
    print '<p>' .
      t('Which contacts should be tagged as part of this activity?') .
      '</p>';
    self::contact_reference();
  }

  static function activity_assignee_contact_id() {
    civicrm_initialize();
    print '<p>';
    if (CRM_Core_BAO_Setting::getItem(CRM_Core_BAO_Setting::SYSTEM_PREFERENCES_NAME, 'activity_assignee_notification')) {
      print t('A copy of this activity will be emailed to the assignee.');
    }
    else {
      print t('Assignee notifications are currently disabled in CiviCRM; no email will be sent to the assignee.');
    }
    print '</p>';
    self::contact_reference();
  }

  static function activity_duration() {
    print '<p>' .
      t('Total time spent on this activity (in minutes).') .
      '</p>';
  }

  static function existing_activity_status() {
    print '<p>' .
      t('If any of these options are selected and a matching activity of the chosen type already exists for Contact 1, it will be autofilled and updated.') .
      '</p><p>' .
      t('Note: an activity can also be autofilled by passing "aid" in the url.') .
      '</p>';
  }

  static function existing_case_activity_status() {
    print '<p>' .
      t('If any of these options are selected and a matching activity of the chosen type already exists for this case, it will be autofilled and updated.') .
      '</p><p>' .
      t('Note: an activity can also be autofilled by passing "aid" in the url.') .
      '</p>';
  }

  static function existing_case_status() {
    print '<p>' .
      t('If any of these options are selected and a matching case of the chosen type already exists for the client, it will be autofilled and updated.') .
      '</p><p>' .
      t('Note: a case can also be autofilled by passing "caseid" in the url.') .
      '</p>';
  }

  static function case_medium_id() {
    print '<p>' .
      t('Medium for activities added to cases from this webform.') .
      '</p>';
  }

  static function contact_reference() {
    print '<p>' .
      t('This is a contact reference field. Webform gives you a great deal of flexibility about how this field is displayed:') .
      '</p><ul>' .
      '<li>' . t('First choose a contact on this webform as the target for this field (or add a new contact to the form for that purpose).') . '</li>' .
      '<li>' . t('In rare cases you might want to expose the list of webform contacts ("User Select").') . '</li>' .
      '<li>' . t('To enable a selection of contacts, enable the "Existing Contact" field for the selected contact.') . '</li>' .
      '<li>' . t('This allows the contact to be selected on the form via autocomplete or dropdown select, or hidden and set to always be the same contact.') . '</li>' .
      '<li>' . t('There are many more possibilities, see "Existing Contact" field help for more information.') . '</li>' .
      '</ul>';
  }

  /**
   * Get help for a custom field
   */
  static function custom($field) {
    list( , $id) = explode('_', $field);
    if (!is_numeric($id)) {
      return;
    }
    civicrm_initialize();
    module_load_include('inc', 'webform_civicrm', 'includes/utils');
    $info = wf_civicrm_api('custom_field', 'getsingle', array('id' => $id));
    if (!empty($info['help_pre'])) {
      print '<p>' . $info['help_pre'] . '</p>';
    }
    if (!empty($info['help_post'])) {
      print '<p>' . $info['help_post'] . '</p>';
    }
  }

  /**
   * Copied from Core CiviCRM's templates/notifications.tpl
   * @return string
   */
  static function helpTemplate() {
    return '
    <div class="crm-container">
      <div id="crm-notification-container" style="display:none">
        <div id="crm-notification-alert" class="#{type}">
          <div class="icon ui-notify-close" title="' . t('close') . '"> </div>
          <a class="ui-notify-cross ui-notify-close" href="#" title="' . t('close') . '">x</a>
          <h1>#{title}</h1>
          <div class="notify-content">#{text}</div>
        </div>
      </div>
    </div>';
  }
}

/**
 * Ajax page callback
 * @param string $topic
 */
function wf_crm_admin_help($topic) {
  if (method_exists('wf_crm_admin_help', $topic)) {
    wf_crm_admin_help::$topic();
  }
  elseif (strpos($topic, 'custom_') === 0) {
    wf_crm_admin_help::custom($topic);
  }
  exit();
}