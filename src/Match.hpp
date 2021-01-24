//
// Created by PinkySmile on 18/01/2021.
//

#ifndef CHALLONGELIB_MATCH_HPP
#define CHALLONGELIB_MATCH_HPP


#include "json.hpp"
#include "Time.hpp"

using json = nlohmann::json;

namespace ChallongeAPI
{
	class Client;
	class Tournament;
	class Participant;

	class Match {
	private:
		std::optional<json>                      _attachmentCount;
		std::optional<Time>                      _completedAt;
		Time                                     _createdAt;
		std::optional<json>                      _forfeited;
		std::optional<json>                      _groupId;
		bool                                     _hasAttachment;
		size_t                                   _id;
		std::string                              _identifier;
		std::optional<json>                      _location;
		std::optional<json>                      _openGraphImageContentType;
		std::optional<json>                      _openGraphImageFileName;
		std::optional<json>                      _openGraphImageFileSize;
		std::optional<bool>                      _optional;
		bool                                     _player1IsPrereqMatchLoser;
		std::optional<size_t>                    _player1PrereqMatchId;
		std::optional<json>                      _player1Votes;
		bool                                     _player2IsPrereqMatchLoser;
		std::optional<size_t>                    _player2PrereqMatchId;
		std::optional<json>                      _player2Votes;
		std::vector<size_t>                      _prerequisiteMatchIds;
		int                                      _round;
		std::optional<json>                      _rushbId;
		std::optional<Time>                      _scheduledTime;
		std::optional<std::pair<size_t, size_t>> _scores;
		std::optional<Time>                      _startedAt;
		std::string                              _state;
		unsigned                                 _suggestedPlayOrder;
		size_t                                   _tournamentId;
		std::optional<json>                      _underwayAt;
		Time                                     _updatedAt;
		std::optional<size_t>                    _loserId;
		std::optional<size_t>                    _winnerId;
		std::optional<size_t>                    _player1Id;
		std::optional<size_t>                    _player2Id;

	public:
		Match(Client &client, const Tournament &tournament, const json &val);
		Match(const Match &) = delete;
		Match(const Match &&) = delete;
		Match &operator=(const Match &) = delete;
		Match &operator=(const Match &&) = delete;

		const std::optional<json>                      &getAttachmentCount() const;
		const std::optional<Time>                      &getCompletedAt() const;
		const Time                                     &getCreatedAt() const;
		const std::optional<json>                      &getForfeited() const;
		const std::optional<json>                      &getGroupId() const;
		bool                                           hasAttachment() const;
		size_t                                         getId() const;
		const std::string                              &getIdentifier() const;
		const std::optional<json>                      &getLocation() const;
		const std::optional<json>                      &getOpenGraphImageContentType() const;
		const std::optional<json>                      &getOpenGraphImageFileName() const;
		const std::optional<json>                      &getOpenGraphImageFileSize() const;
		const std::optional<bool>                      &getOptional() const;
		bool                                           isPlayer1IsPrereqMatchLoser() const;
		const std::optional<size_t>                    &getPlayer1PrereqMatchId() const;
		const std::optional<json>                      &getPlayer1Votes() const;
		bool                                           isPlayer2IsPrereqMatchLoser() const;
		const std::optional<size_t>                    &getPlayer2PrereqMatchId() const;
		const std::optional<json>                      &getPlayer2Votes() const;
		const std::vector<size_t>                      &getPrerequisiteMatchIds() const;
		int                                            getRound() const;
		const std::optional<json>                      &getRushbId() const;
		const std::optional<Time>                      &getScheduledTime() const;
		const std::optional<std::pair<size_t, size_t>> &getScores() const;
		const std::optional<Time>                      &getStartedAt() const;
		const std::string                              &getState() const;
		unsigned int                                   getSuggestedPlayOrder() const;
		size_t                                         getTournamentId() const;
		const std::optional<json>                      &getUnderwayAt() const;
		const Time                                     &getUpdatedAt() const;
		const std::optional<size_t>                    &getLoserId() const;
		const std::optional<size_t>                    &getWinnerId() const;
		const std::optional<size_t>                    &getPlayer1Id() const;
		const std::optional<size_t>                    &getPlayer2Id() const;
	};
}


#endif //CHALLONGELIB_MATCH_HPP
