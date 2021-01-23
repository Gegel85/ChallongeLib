//
// Created by PinkySmile on 18/01/2021.
//

#include "Match.hpp"
#include "Tournament.hpp"
#include "JsonUtils.hpp"

namespace ChallongeAPI
{
	Match::Match(Client &client, const Tournament &tournament, const json &val)
	{
		auto &value = val["match"];

		getFromJson(this->_attachmentCount, "attachment_count", value);
		getFromJson(this->_completedAt, "completed_at", value);
		getFromJson(this->_createdAt, "created_at", value);
		getFromJson(this->_forfeited, "forfeited", value);
		getFromJson(this->_groupId, "group_id", value);
		getFromJson(this->_hasAttachment, "has_attachment", value);
		getFromJson(this->_id, "id", value);
		getFromJson(this->_identifier, "identifier", value);
		getFromJson(this->_location, "location", value);
		getFromJson(this->_openGraphImageContentType, "open_graph_image_content_type", value);
		getFromJson(this->_openGraphImageFileName, "open_graph_image_file_name", value);
		getFromJson(this->_openGraphImageFileSize, "open_graph_image_file_size", value);
		getFromJson(this->_optional, "optional", value);
		getFromJson(this->_player1IsPrereqMatchLoser, "player1_is_prereq_match_loser", value);
		getFromJson(this->_player1PrereqMatchId, "player1_prereq_match_id", value);
		getFromJson(this->_player1Votes, "player1_votes", value);
		getFromJson(this->_player2IsPrereqMatchLoser, "player2_is_prereq_match_loser", value);
		getFromJson(this->_player2PrereqMatchId, "player2_prereq_match_id", value);
		getFromJson(this->_player2Votes, "player2_votes", value);
		getFromJson(this->_round, "round", value);
		getFromJson(this->_rushbId, "rushb_id", value);
		getFromJson(this->_scheduledTime, "scheduled_time", value);
		getFromJson(this->_startedAt, "started_at", value);
		getFromJson(this->_state, "state", value);
		getFromJson(this->_suggestedPlayOrder, "suggested_play_order", value);
		getFromJson(this->_tournamentId, "tournament_id", value);
		getFromJson(this->_underwayAt, "underway_at", value);
		getFromJson(this->_updatedAt, "updated_at", value);
		getFromJson(this->_player1Id, "player1_id", value);
		getFromJson(this->_player2Id, "player2_id", value);
		getFromJson(this->_loserId, "loser_id", value);
		getFromJson(this->_winnerId, "winner_id", value);

		getFromJson(this->_prerequisiteMatchIds, "prerequisite_match_ids_csv", value);
		getFromJson(this->_scores, "scores_csv", value);
	}

	const std::optional<json> &Match::getAttachmentCount() const
	{
		return this->_attachmentCount;
	}

	const std::optional<Time> &Match::getCompletedAt() const
	{
		return this->_completedAt;
	}

	const Time &Match::getCreatedAt() const
	{
		return this->_createdAt;
	}

	const std::optional<json> &Match::getForfeited() const
	{
		return this->_forfeited;
	}

	const std::optional<json> &Match::getGroupId() const
	{
		return this->_groupId;
	}

	bool Match::hasAttachment() const
	{
		return this->_hasAttachment;
	}

	size_t Match::getId() const
	{
		return this->_id;
	}

	const std::string &Match::getIdentifier() const
	{
		return this->_identifier;
	}

	const std::optional<json> &Match::getLocation() const
	{
		return this->_location;
	}

	const std::optional<json> &Match::getOpenGraphImageContentType() const
	{
		return this->_openGraphImageContentType;
	}

	const std::optional<json> &Match::getOpenGraphImageFileName() const
	{
		return this->_openGraphImageFileName;
	}

	const std::optional<json> &Match::getOpenGraphImageFileSize() const
	{
		return this->_openGraphImageFileSize;
	}

	const std::optional<bool> &Match::getOptional() const
	{
		return this->_optional;
	}

	bool Match::isPlayer1IsPrereqMatchLoser() const
	{
		return this->_player1IsPrereqMatchLoser;
	}

	const std::optional<size_t> &Match::getPlayer1PrereqMatchId() const
	{
		return this->_player1PrereqMatchId;
	}

	const std::optional<json> &Match::getPlayer1Votes() const
	{
		return this->_player1Votes;
	}

	bool Match::isPlayer2IsPrereqMatchLoser() const
	{
		return this->_player2IsPrereqMatchLoser;
	}

	const std::optional<size_t> &Match::getPlayer2PrereqMatchId() const
	{
		return this->_player2PrereqMatchId;
	}

	const std::optional<json> &Match::getPlayer2Votes() const
	{
		return this->_player2Votes;
	}

	const std::vector<size_t> &Match::getPrerequisiteMatchIds() const
	{
		return this->_prerequisiteMatchIds;
	}

	int Match::getRound() const
	{
		return this->_round;
	}

	const std::optional<json> &Match::getRushbId() const
	{
		return this->_rushbId;
	}

	const std::optional<Time> &Match::getScheduledTime() const
	{
		return this->_scheduledTime;
	}

	const std::vector<size_t> &Match::getScores() const
	{
		return this->_scores;
	}

	const Time &Match::getStartedAt() const
	{
		return this->_startedAt;
	}

	const std::string &Match::getState() const
	{
		return this->_state;
	}

	unsigned int Match::getSuggestedPlayOrder() const
	{
		return this->_suggestedPlayOrder;
	}

	size_t Match::getTournamentId() const
	{
		return this->_tournamentId;
	}

	const std::optional<json> &Match::getUnderwayAt() const
	{
		return this->_underwayAt;
	}

	const Time &Match::getUpdatedAt() const
	{
		return this->_updatedAt;
	}

	const std::optional<size_t> &Match::getLoserId() const
	{
		return this->_loserId;
	}

	const std::optional<size_t> &Match::getWinnerId() const
	{
		return this->_winnerId;
	}

	size_t Match::getPlayer1Id() const
	{
		return this->_player1Id;
	}

	size_t Match::getPlayer2Id() const
	{
		return this->_player2Id;
	}
}