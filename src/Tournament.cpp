//
// Created by PinkySmile on 18/01/2021.
//

#include "Tournament.hpp"
#include "JsonUtils.hpp"

namespace ChallongeAPI
{
	Tournament::Tournament(Client &client) :
		_client(client)
	{
	}

	Tournament::Tournament(Client &client, const json &v) :
		Tournament(client)
	{
		*this = v;
	}

	Tournament &Tournament::operator=(const json &v)
	{
		const auto &value = v["tournament"];

		getFromJson(this->_acceptAttachments, "accept_attachments", value);
		getFromJson(this->_acceptingPredictions, "accepting_predictions", value);
		getFromJson(this->_allowParticipantMatchReporting, "allow_participant_match_reporting", value);
		getFromJson(this->_allowedRegions, "allowed_regions", value);
		getFromJson(this->_anonymousVoting, "anonymous_voting", value);
		getFromJson(this->_autoAssignStations, "auto_assign_stations", value);
		getFromJson(this->_category, "category", value);
		getFromJson(this->_checkInDuration, "check_in_duration", value);
		getFromJson(this->_completedAt, "completed_at", value);
		getFromJson(this->_createdAt, "created_at", value);
		getFromJson(this->_createdByApi, "created_by_api", value);
		getFromJson(this->_creditCapped, "credit_capped", value);
		getFromJson(this->_description, "description", value);
		getFromJson(this->_descriptionSource, "description_source", value);
		getFromJson(this->_donationContestEnabled, "donation_contest_enabled", value);
		getFromJson(this->_eventId, "event_id", value);
		getFromJson(this->_fullChallongeUrl, "full_challonge_url", value);
		getFromJson(this->_gameId, "game_id", value);
		getFromJson(this->_gameName, "game_name", value);
		getFromJson(this->_grandFinalsModifier, "grand_finals_modifier", value);
		getFromJson(this->_groupStagesEnabled, "group_stages_enabled", value);
		getFromJson(this->_groupStagesWereStarted, "group_stages_were_started", value);
		getFromJson(this->_ham, "ham", value);
		getFromJson(this->_hideForum, "hide_forum", value);
		getFromJson(this->_hideSeeds, "hide_seeds", value);
		getFromJson(this->_holdThirdPlaceMatch, "hold_third_place_match", value);
		getFromJson(this->_id, "id", value);
		getFromJson(this->_liveImageUrl, "live_image_url", value);
		getFromJson(this->_lockedAt, "locked_at", value);
		getFromJson(this->_mandatoryDonation, "mandatory_donation", value);
		getFromJson(this->_maxPredictionsPerUser, "max_predictions_per_user", value);
		getFromJson(this->_name, "name", value);
		getFromJson(this->_nonEliminationTournamentData, "non_elimination_tournament_data", value);
		getFromJson(this->_notifyUsersWhenMatchesOpen, "notify_users_when_matches_open", value);
		getFromJson(this->_notifyUsersWhenTheTournamentEnds, "notify_users_when_the_tournament_ends", value);
		getFromJson(this->_onlyStartMatchesWithStations, "only_start_matches_with_stations", value);
		getFromJson(this->_openSignup, "open_signup", value);
		getFromJson(this->_participants, "participants", value, this->_client);
		getFromJson(this->_matches, "matches", value, this->_client, *this);
		getFromJson(this->_participantsCount, "participants_count", value);
		getFromJson(this->_participantsLocked, "participants_locked", value);
		getFromJson(this->_participantsSwappable, "participants_swappable", value);
		getFromJson(this->_predictTheLosersBracket, "predict_the_losers_bracket", value);
		getFromJson(this->_predictionMethod, "prediction_method", value);
		getFromJson(this->_predictionsOpenedAt, "predictions_opened_at", value);
		getFromJson(this->_private, "private", value);
		getFromJson(this->_programClassificationIdsAllowed, "program_classification_ids_allowed", value);
		getFromJson(this->_programId, "program_id", value);
		getFromJson(this->_progressMeter, "progress_meter", value);
		getFromJson(this->_ptsForBye, "pts_for_bye", value);
		getFromJson(this->_ptsForGameTie, "pts_for_game_tie", value);
		getFromJson(this->_ptsForGameWin, "pts_for_game_win", value);
		getFromJson(this->_ptsForMatchTie, "pts_for_match_tie", value);
		getFromJson(this->_ptsForMatchWin, "pts_for_match_win", value);
		getFromJson(this->_publicPredictionsBeforeStartTime, "public_predictions_before_start_time", value);
		getFromJson(this->_quickAdvance, "quick_advance", value);
		getFromJson(this->_ranked, "ranked", value);
		getFromJson(this->_rankedBy, "ranked_by", value);
		getFromJson(this->_registrationFee, "registration_fee", value);
		getFromJson(this->_registrationType, "registration_type", value);
		getFromJson(this->_requireScoreAgreement, "require_score_agreement", value);
		getFromJson(this->_reviewBeforeFinalizing, "review_before_finalizing", value);
		getFromJson(this->_rrIterations, "rr_iterations", value);
		getFromJson(this->_rrPtsForGameTie, "rr_pts_for_game_tie", value);
		getFromJson(this->_rrPtsForGameWin, "rr_pts_for_game_win", value);
		getFromJson(this->_rrPtsForMatchTie, "rr_pts_for_match_tie", value);
		getFromJson(this->_rrPtsForMatchWin, "rr_pts_for_match_win", value);
		getFromJson(this->_sequentialPairings, "sequential_pairings", value);
		getFromJson(this->_showParticipantCountry, "show_participant_country", value);
		getFromJson(this->_showRounds, "show_rounds", value);
		getFromJson(this->_signUpUrl, "sign_up_url", value);
		getFromJson(this->_signupCap, "sign_up_cap", value);
		getFromJson(this->_spam, "spam", value);
		getFromJson(this->_splitParticipants, "split_participants", value);
		getFromJson(this->_startAt, "start_at", value);
		getFromJson(this->_startedAt, "started_at", value);
		getFromJson(this->_startedChecking_in_at, "started_checking_in_at", value);
		getFromJson(this->_state, "state", value);
		getFromJson(this->_subdomain, "subdomain", value);
		getFromJson(this->_swissRounds, "swiss_rounds", value);
		getFromJson(this->_teamConvertable, "team_convertable", value);
		getFromJson(this->_teams, "teams", value);
		getFromJson(this->_tieBreaks, "tie_breaks", value);
		getFromJson(this->_tournamentRegistrationId, "tournament_registration_id", value);
		getFromJson(this->_tournamentType, "tournament_type", value);
		getFromJson(this->_updatedAt, "updated_at", value);
		getFromJson(this->_url, "url", value);
		return *this;
	}

	bool Tournament::acceptsAttachments() const
	{
		return this->_acceptAttachments;
	}

	bool Tournament::isAcceptingPredictions() const
	{
		return this->_acceptingPredictions;
	}

	bool Tournament::isAllowParticipantMatchReporting() const
	{
		return this->_allowParticipantMatchReporting;
	}

	const std::vector<json> &Tournament::getAllowedRegions() const
	{
		return this->_allowedRegions;
	}

	bool Tournament::hasAnonymousVoting() const
	{
		return this->_anonymousVoting;
	}

	const std::optional<json> &Tournament::getAutoAssignStations() const
	{
		return this->_autoAssignStations;
	}

	const std::optional<json> &Tournament::getCategory() const
	{
		return this->_category;
	}

	size_t Tournament::getCheckInDuration() const
	{
		return this->_checkInDuration;
	}

	const std::optional<Time> &Tournament::getCompletedAt() const
	{
		return this->_completedAt;
	}

	const Time &Tournament::getCreatedAt() const
	{
		return this->_createdAt;
	}

	bool Tournament::isCreatedByApi() const
	{
		return this->_createdByApi;
	}

	bool Tournament::isCreditCapped() const
	{
		return this->_creditCapped;
	}

	const std::string &Tournament::getDescription() const
	{
		return this->_description;
	}

	const std::string &Tournament::getDescriptionSource() const
	{
		return this->_descriptionSource;
	}

	const std::optional<json> &Tournament::getDonationContestEnabled() const
	{
		return this->_donationContestEnabled;
	}

	const std::optional<json> &Tournament::getEventId() const
	{
		return this->_eventId;
	}

	const std::string &Tournament::getFullChallongeUrl() const
	{
		return this->_fullChallongeUrl;
	}

	size_t Tournament::getGameId() const
	{
		return this->_gameId;
	}

	const std::string &Tournament::getGameName() const
	{
		return this->_gameName;
	}

	const std::optional<json> &Tournament::getGrandFinalsModifier() const
	{
		return this->_grandFinalsModifier;
	}

	bool Tournament::isGroupStagesEnabled() const
	{
		return this->_groupStagesEnabled;
	}

	bool Tournament::isGroupStagesWereStarted() const
	{
		return this->_groupStagesWereStarted;
	}

	const std::optional<json> &Tournament::getHam() const
	{
		return this->_ham;
	}

	bool Tournament::isForumHidden() const
	{
		return this->_hideForum;
	}

	bool Tournament::areSeedsHidden() const
	{
		return this->_hideSeeds;
	}

	bool Tournament::areThirdPlaceMatchHeld() const
	{
		return this->_holdThirdPlaceMatch;
	}

	size_t Tournament::getId() const
	{
		return this->_id;
	}

	const std::string &Tournament::getLiveImageUrl() const
	{
		return this->_liveImageUrl;
	}

	const std::optional<Time> &Tournament::getLockedAt() const
	{
		return this->_lockedAt;
	}

	const std::optional<json> &Tournament::getMandatoryDonation() const
	{
		return this->_mandatoryDonation;
	}

	std::vector<std::shared_ptr<Match>> Tournament::getMatches() const
	{
		return this->_matches;
	}

	size_t Tournament::getMaxPredictionsPerUser() const
	{
		return this->_maxPredictionsPerUser;
	}

	const std::string &Tournament::getName() const
	{
		return this->_name;
	}

	const json &Tournament::getNonEliminationTournamentData() const
	{
		return this->_nonEliminationTournamentData;
	}

	bool Tournament::areUsersNotifiedWhenMatchesOpen() const
	{
		return this->_notifyUsersWhenMatchesOpen;
	}

	bool Tournament::areUsersNotifiedWhenTheTournamentEnds() const
	{
		return this->_notifyUsersWhenTheTournamentEnds;
	}

	const std::optional<json> &Tournament::getOnlyStartMatchesWithStations() const
	{
		return this->_onlyStartMatchesWithStations;
	}

	bool Tournament::isSignupOpen() const
	{
		return this->_openSignup;
	}

	std::vector<std::shared_ptr<Participant>> Tournament::getParticipants() const
	{
		return this->_participants;
	}

	size_t Tournament::getParticipantsCount() const
	{
		return this->_participantsCount;
	}

	bool Tournament::isParticipantsLocked() const
	{
		return this->_participantsLocked;
	}

	bool Tournament::isParticipantsSwappable() const
	{
		return this->_participantsSwappable;
	}

	bool Tournament::canPredictTheLosersBracket() const
	{
		return this->_predictTheLosersBracket;
	}

	size_t Tournament::getPredictionMethod() const
	{
		return this->_predictionMethod;
	}

	const std::optional<Time> &Tournament::getPredictionsOpenedAt() const
	{
		return this->_predictionsOpenedAt;
	}

	bool Tournament::isPrivate() const
	{
		return this->_private;
	}

	const std::optional<json> &Tournament::getProgramClassificationIdsAllowed() const
	{
		return this->_programClassificationIdsAllowed;
	}

	const std::optional<size_t> &Tournament::getProgramId() const
	{
		return this->_programId;
	}

	size_t Tournament::getProgressMeter() const
	{
		return this->_progressMeter;
	}

	float Tournament::getPtsForBye() const
	{
		return this->_ptsForBye;
	}

	float Tournament::getPtsForGameTie() const
	{
		return this->_ptsForGameTie;
	}

	float Tournament::getPtsForGameWin() const
	{
		return this->_ptsForGameWin;
	}

	float Tournament::getPtsForMatchTie() const
	{
		return this->_ptsForMatchTie;
	}

	float Tournament::getPtsForMatchWin() const
	{
		return this->_ptsForMatchWin;
	}

	bool Tournament::arePublicPredictionsBeforeStartTimeAllowed() const
	{
		return this->_publicPredictionsBeforeStartTime;
	}

	bool Tournament::isQuickAdvanceEnabled() const
	{
		return this->_quickAdvance;
	}

	bool Tournament::isRanked() const
	{
		return this->_ranked;
	}

	const std::string &Tournament::getRankedBy() const
	{
		return this->_rankedBy;
	}

	float Tournament::getRegistrationFee() const
	{
		return this->_registrationFee;
	}

	const std::string &Tournament::getRegistrationType() const
	{
		return this->_registrationType;
	}

	bool Tournament::requiresScoreAgreement() const
	{
		return this->_requireScoreAgreement;
	}

	bool Tournament::areReviewMandatoryBeforeFinalizing() const
	{
		return this->_reviewBeforeFinalizing;
	}

	size_t Tournament::getRrIterations() const
	{
		return this->_rrIterations;
	}

	float Tournament::getRrPtsForGameTie() const
	{
		return this->_rrPtsForGameTie;
	}

	float Tournament::getRrPtsForGameWin() const
	{
		return this->_rrPtsForGameWin;
	}

	float Tournament::getRrPtsForMatchTie() const
	{
		return this->_rrPtsForMatchTie;
	}

	float Tournament::getRrPtsForMatchWin() const
	{
		return this->_rrPtsForMatchWin;
	}

	bool Tournament::isPairingsSequential() const
	{
		return this->_sequentialPairings;
	}

	const std::optional<json> &Tournament::getShowParticipantCountry() const
	{
		return this->_showParticipantCountry;
	}

	bool Tournament::areRoundsShown() const
	{
		return this->_showRounds;
	}

	const std::string &Tournament::getSignUpUrl() const
	{
		return this->_signUpUrl;
	}

	const std::optional<json> &Tournament::getSignupCap() const
	{
		return this->_signupCap;
	}

	const std::optional<json> &Tournament::getSpam() const
	{
		return this->_spam;
	}

	bool Tournament::areParticipantsSplit() const
	{
		return this->_splitParticipants;
	}

	const Time &Tournament::getStartAt() const
	{
		return this->_startAt;
	}

	const std::optional<Time> &Tournament::getStartedAt() const
	{
		return this->_startedAt;
	}

	const std::optional<Time> &Tournament::getStartedCheckingInAt() const
	{
		return this->_startedChecking_in_at;
	}

	const std::string &Tournament::getState() const
	{
		return this->_state;
	}

	const std::optional<json> &Tournament::getSubdomain() const
	{
		return this->_subdomain;
	}

	size_t Tournament::getSwissRounds() const
	{
		return this->_swissRounds;
	}

	bool Tournament::isTeamConvertable() const
	{
		return this->_teamConvertable;
	}

	bool Tournament::hasTeams() const
	{
		return this->_teams;
	}

	const std::vector<std::string> &Tournament::getTieBreaks() const
	{
		return this->_tieBreaks;
	}

	const std::optional<size_t> &Tournament::getTournamentRegistrationId() const
	{
		return this->_tournamentRegistrationId;
	}

	const std::string &Tournament::getTournamentType() const
	{
		return this->_tournamentType;
	}

	const std::optional<Time> &Tournament::getUpdatedAt() const
	{
		return this->_updatedAt;
	}

	const std::string &Tournament::getUrl() const
	{
		return this->_url;
	}
}