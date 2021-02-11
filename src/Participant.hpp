//
// Created by PinkySmile on 18/01/2021.
//

#ifndef CHALLONGELIB_PARTICIPANT_HPP
#define CHALLONGELIB_PARTICIPANT_HPP


#include "json.hpp"
#include "Time.hpp"

using json = nlohmann::json;

namespace ChallongeAPI
{
	class Client;
	class Tournament;

	class Participant {
	private:
		Client                     &_client;
		bool                       _active;
		std::optional<std::string> _attachedParticipatablePortraitUrl;
		bool                       _canCheckIn;
		std::optional<bool>        _challongeEmailAddressVerified;
		std::optional<std::string> _challongeUsername;
		bool                       _checkInOpen;
		bool                       _checkedIn;
		std::optional<Time>        _checkedInAt;
		std::optional<json>        _clinch;
		bool                       _confirmRemove;
		Time                       _createdAt;
		std::optional<json>        _customFieldResponse;
		std::string                _displayName;
		std::string                _displayNameWithInvitationEmailAddress;
		std::optional<std::string> _emailHash;
		std::optional<json>        _finalRank;
		std::optional<json>        _groupId;
		std::vector<size_t>        _groupPlayerIds;
		bool                       _hasIrrelevantSeed;
		std::optional<json>        _icon;
		unsigned long              _id;
		std::optional<json>        _integrationUids;
		std::optional<json>        _invitationId;
		bool                       _invitationPending;
		std::optional<json>        _inviteEmail;
		std::optional<json>        _misc;
		std::string                _name;
		bool                       _onWaitingList;
		bool                       _participatableOrInvitationAttached;
		std::optional<json>        _rankedMemberId;
		bool                       _reactivatable;
		bool                       _removable;
		unsigned long              _seed;
		Tournament                 &_tournament;
		std::optional<Time>        _updatedAt;
		std::optional<std::string> _username;

	public:
		Participant(Client &client, const json &val);
		Participant(const Participant &) = delete;
		Participant(const Participant &&) = delete;
		Participant &operator=(const Participant &) = delete;
		Participant &operator=(const Participant &&) = delete;

		bool                             isActive() const;
		const std::optional<std::string> &getAttachedParticipatablePortraitUrl() const;
		bool                             canCheckIn() const;
		const std::optional<bool>        &isChallongeEmailAddressVerified() const;
		const std::optional<std::string> &getChallongeUsername() const;
		bool                             areCheckInOpen() const;
		bool                             isCheckedIn() const;
		const std::optional<Time>        &getCheckedInAt() const;
		const std::optional<json>        &getClinch() const;
		bool                             doConfirmRemove() const;
		const Time                       &getCreatedAt() const;
		const std::optional<json>        &getCustomFieldResponse() const;
		const std::string                &getDisplayName() const;
		const std::string                &getDisplayNameWithInvitationEmailAddress() const;
		const std::optional<std::string> &getEmailHash() const;
		const std::optional<json>        &getFinalRank() const;
		const std::optional<json>        &getGroupId() const;
		const std::vector<size_t>        &getGroupPlayerIds() const;
		bool                             hasIrrelevantSeed() const;
		const std::optional<json>        &getIcon() const;
		unsigned long                    getId() const;
		const std::optional<json>        &getIntegrationUids() const;
		const std::optional<json>        &getInvitationId() const;
		bool                             isInvitationPending() const;
		const std::optional<json>        &getInviteEmail() const;
		const std::optional<json>        &getMisc() const;
		const std::string                &getName() const;
		bool                             isOnWaitingList() const;
		bool                             isParticipatableOrInvitationAttached() const;
		const std::optional<json>        &getRankedMemberId() const;
		bool                             isReactivatable() const;
		bool                             isRemovable() const;
		unsigned long                    getSeed() const;
		Tournament                       &getTournament() const;
		const std::optional<Time>        &getUpdatedAt() const;
		const std::optional<std::string> &getUsername() const;
	};
}


#endif //CHALLONGELIB_PARTICIPANT_HPP
