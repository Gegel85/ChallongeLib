//
// Created by PinkySmile on 18/01/2021.
//

#include "JsonUtils.hpp"
#include "Client.hpp"
#include "Participant.hpp"

namespace ChallongeAPI
{
	Participant::Participant(Client &client, const json &val) :
		_client(client),
		_tournament(*[&val, &client]{
			unsigned long id;

			getFromJson(id, "tournament_id", val["participant"]);
			return client.getTournamentById(id);
		}())
	{
		const auto &value = val["participant"];

		getFromJson(this->_active, "active", value);
		getFromJson(this->_attachedParticipatablePortraitUrl, "attached_participatable_portrait_url", value);
		getFromJson(this->_canCheckIn, "can_check_in", value);
		getFromJson(this->_challongeEmailAddressVerified, "challonge_email_address_verified", value);
		getFromJson(this->_challongeUsername, "challonge_username", value);
		getFromJson(this->_checkInOpen, "check_in_open", value);
		getFromJson(this->_checkedIn, "checked_in", value);
		getFromJson(this->_checkedInAt, "checked_in_at", value);
		getFromJson(this->_clinch, "clinch", value);
		getFromJson(this->_confirmRemove, "confirm_remove", value);
		getFromJson(this->_createdAt, "created_at", value);
		getFromJson(this->_customFieldResponse, "custom_field_response", value);
		getFromJson(this->_displayName, "display_name", value);
		getFromJson(this->_displayNameWithInvitationEmailAddress, "display_name_with_invitation_email_address", value);
		getFromJson(this->_emailHash, "email_hash", value);
		getFromJson(this->_finalRank, "final_rank", value);
		getFromJson(this->_groupId, "group_id", value);
		getFromJson(this->_groupPlayerIds, "group_player_ids", value);
		getFromJson(this->_hasIrrelevantSeed, "has_irrelevant_seed", value);
		getFromJson(this->_icon, "icon", value);
		getFromJson(this->_id, "id", value);
		getFromJson(this->_integrationUids, "integration_uids", value);
		getFromJson(this->_invitationId, "invitation_id", value);
		getFromJson(this->_invitationPending, "invitation_pending", value);
		getFromJson(this->_inviteEmail, "invite_email", value);
		getFromJson(this->_misc, "misc", value);
		getFromJson(this->_name, "name", value);
		getFromJson(this->_onWaitingList, "on_waiting_list", value);
		getFromJson(this->_participatableOrInvitationAttached, "participatable_or_invitation_attached", value);
		getFromJson(this->_rankedMemberId, "ranked_member_id", value);
		getFromJson(this->_reactivatable, "reactivatable", value);
		getFromJson(this->_removable, "removable", value);
		getFromJson(this->_seed, "seed", value);
		getFromJson(this->_updatedAt, "updated_at", value);
		getFromJson(this->_username, "username", value);
	}

	bool Participant::isActive() const
	{
		return this->_active;
	}

	const std::optional<std::string> &Participant::getAttachedParticipatablePortraitUrl() const
	{
		return this->_attachedParticipatablePortraitUrl;
	}

	bool Participant::canCheckIn() const
	{
		return this->_canCheckIn;
	}

	const std::optional<bool> &Participant::isChallongeEmailAddressVerified() const
	{
		return this->_challongeEmailAddressVerified;
	}

	const std::optional<std::string> &Participant::getChallongeUsername() const
	{
		return this->_challongeUsername;
	}

	bool Participant::areCheckInOpen() const
	{
		return this->_checkInOpen;
	}

	bool Participant::isCheckedIn() const
	{
		return this->_checkedIn;
	}

	const std::optional<Time> &Participant::getCheckedInAt() const
	{
		return this->_checkedInAt;
	}

	const std::optional<json> &Participant::getClinch() const
	{
		return this->_clinch;
	}

	bool Participant::doConfirmRemove() const
	{
		return this->_confirmRemove;
	}

	const Time &Participant::getCreatedAt() const
	{
		return this->_createdAt;
	}

	const std::optional<json> &Participant::getCustomFieldResponse() const
	{
		return this->_customFieldResponse;
	}

	const std::string &Participant::getDisplayName() const
	{
		return this->_displayName;
	}

	const std::string &Participant::getDisplayNameWithInvitationEmailAddress() const
	{
		return this->_displayNameWithInvitationEmailAddress;
	}

	const std::optional<std::string> &Participant::getEmailHash() const
	{
		return this->_emailHash;
	}

	const std::optional<json> &Participant::getFinalRank() const
	{
		return this->_finalRank;
	}

	const std::optional<json> &Participant::getGroupId() const
	{
		return this->_groupId;
	}

	const std::vector<size_t> &Participant::getGroupPlayerIds() const
	{
		return this->_groupPlayerIds;
	}

	bool Participant::hasIrrelevantSeed() const
	{
		return this->_hasIrrelevantSeed;
	}

	const std::optional<json> &Participant::getIcon() const
	{
		return this->_icon;
	}

	unsigned long Participant::getId() const
	{
		return this->_id;
	}

	const std::optional<json> &Participant::getIntegrationUids() const
	{
		return this->_integrationUids;
	}

	const std::optional<json> &Participant::getInvitationId() const
	{
		return this->_invitationId;
	}

	bool Participant::isInvitationPending() const
	{
		return this->_invitationPending;
	}

	const std::optional<json> &Participant::getInviteEmail() const
	{
		return this->_inviteEmail;
	}

	const std::optional<json> &Participant::getMisc() const
	{
		return this->_misc;
	}

	const std::string &Participant::getName() const
	{
		return this->_name;
	}

	bool Participant::isOnWaitingList() const
	{
		return this->_onWaitingList;
	}

	bool Participant::isParticipatableOrInvitationAttached() const
	{
		return this->_participatableOrInvitationAttached;
	}

	const std::optional<json> &Participant::getRankedMemberId() const
	{
		return this->_rankedMemberId;
	}

	bool Participant::isReactivatable() const
	{
		return this->_reactivatable;
	}

	bool Participant::isRemovable() const
	{
		return this->_removable;
	}

	unsigned long Participant::getSeed() const
	{
		return this->_seed;
	}

	Tournament &Participant::getTournament() const
	{
		return this->_tournament;
	}

	const std::optional<Time> &Participant::getUpdatedAt() const
	{
		return this->_updatedAt;
	}

	const std::optional<std::string> &Participant::getUsername() const
	{
		return this->_username;
	}
}