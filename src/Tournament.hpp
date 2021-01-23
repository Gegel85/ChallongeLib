//
// Created by PinkySmile on 18/01/2021.
//

#ifndef CHALLONGELIB_TOURNAMENT_HPP
#define CHALLONGELIB_TOURNAMENT_HPP


#include <optional>
#include "json.hpp"
#include "Time.hpp"
#include "Participant.hpp"
#include "Match.hpp"

using json = nlohmann::json;

namespace ChallongeAPI
{
	class Client;

	class Tournament {
	private:
		Client                                    &_client;
		bool                                      _acceptAttachments;
		bool                                      _acceptingPredictions;
		bool                                      _allowParticipantMatchReporting;
		std::vector<json>                         _allowedRegions;
		bool                                      _anonymousVoting;
		std::optional<json>                       _autoAssignStations;
		std::optional<json>                       _category;
		size_t                                    _checkInDuration;
		std::optional<Time>                       _completedAt;
		Time                                      _createdAt;
		bool                                      _createdByApi;
		bool                                      _creditCapped;
		std::string                               _description;
		std::string                               _descriptionSource;
		std::optional<json>                       _donationContestEnabled;
		std::optional<json>                       _eventId;
		std::string                               _fullChallongeUrl;
		size_t                                    _gameId;
		std::string                               _gameName;
		std::optional<json>                       _grandFinalsModifier;
		bool                                      _groupStagesEnabled;
		bool                                      _groupStagesWereStarted;
		std::optional<json>                       _ham;
		bool                                      _hideForum;
		bool                                      _hideSeeds;
		bool                                      _holdThirdPlaceMatch;
		size_t                                    _id;
		std::string                               _liveImageUrl;
		std::optional<Time>                       _lockedAt;
		std::optional<json>                       _mandatoryDonation;
		std::vector<std::shared_ptr<Match>>       _matches;
		size_t                                    _maxPredictionsPerUser;
		std::string                               _name;
		json                                      _nonEliminationTournamentData;
		bool                                      _notifyUsersWhenMatchesOpen;
		bool                                      _notifyUsersWhenTheTournamentEnds;
		std::optional<json>                       _onlyStartMatchesWithStations;
		bool                                      _openSignup;
		std::vector<std::shared_ptr<Participant>> _participants;
		size_t                                    _participantsCount;
		bool                                      _participantsLocked;
		bool                                      _participantsSwappable;
		bool                                      _predictTheLosersBracket;
		size_t                                    _predictionMethod;
		std::optional<Time>                       _predictionsOpenedAt;
		bool                                      _private;
		std::optional<json>                       _programClassificationIdsAllowed;
		std::optional<size_t>                     _programId;
		size_t                                    _progressMeter;
		float                                     _ptsForBye;
		float                                     _ptsForGameTie;
		float                                     _ptsForGameWin;
		float                                     _ptsForMatchTie;
		float                                     _ptsForMatchWin;
		bool                                      _publicPredictionsBeforeStartTime;
		bool                                      _quickAdvance;
		bool                                      _ranked;
		std::string                               _rankedBy;
		float                                     _registrationFee;
		std::string                               _registrationType;
		bool                                      _requireScoreAgreement;
		bool                                      _reviewBeforeFinalizing;
		size_t                                    _rrIterations;
		float                                     _rrPtsForGameTie;
		float                                     _rrPtsForGameWin;
		float                                     _rrPtsForMatchTie;
		float                                     _rrPtsForMatchWin;
		bool                                      _sequentialPairings;
		std::optional<json>                       _showParticipantCountry;
		bool                                      _showRounds;
		std::string                               _signUpUrl;
		std::optional<json>                       _signupCap;
		std::optional<json>                       _spam;
		bool                                      _splitParticipants;
		Time                                      _startAt;
		std::optional<Time>                       _startedAt;
		std::optional<Time>                       _startedChecking_in_at;
		std::string                               _state;
		std::optional<json>                       _subdomain;
		size_t                                    _swissRounds;
		bool                                      _teamConvertable;
		bool                                      _teams;
		std::vector<std::string>                  _tieBreaks;
		std::optional<size_t>                     _tournamentRegistrationId;
		std::string                               _tournamentType;
		std::optional<Time>                       _updatedAt;
		std::string                               _url;

	public:
		Tournament(Client &client);
		Tournament(Client &client, const json &value);
		Tournament &operator=(const json &value);
		Tournament(const Tournament &) = delete;
		Tournament(const Tournament &&) = delete;
		Tournament &operator=(const Tournament &) = delete;
		Tournament &operator=(const Tournament &&) = delete;

		// Getters
		bool                                      acceptsAttachments() const;
		bool                                      isAcceptingPredictions() const;
		bool                                      isAllowParticipantMatchReporting() const;
		const std::vector<json>                   &getAllowedRegions() const;
		bool                                      hasAnonymousVoting() const;
		const std::optional<json>                 &getAutoAssignStations() const;
		const std::optional<json>                 &getCategory() const;
		size_t                                    getCheckInDuration() const;
		const std::optional<Time>                 &getCompletedAt() const;
		const Time                                &getCreatedAt() const;
		bool                                      isCreatedByApi() const;
		bool                                      isCreditCapped() const;
		const std::string                         &getDescription() const;
		const std::string                         &getDescriptionSource() const;
		const std::optional<json>                 &getDonationContestEnabled() const;
		const std::optional<json>                 &getEventId() const;
		const std::string                         &getFullChallongeUrl() const;
		size_t                                    getGameId() const;
		const std::string                         &getGameName() const;
		const std::optional<json>                 &getGrandFinalsModifier() const;
		bool                                      isGroupStagesEnabled() const;
		bool                                      isGroupStagesWereStarted() const;
		const std::optional<json>                 &getHam() const;
		bool                                      isForumHidden() const;
		bool                                      areSeedsHidden() const;
		bool                                      areThirdPlaceMatchHeld() const;
		size_t                                    getId() const;
		const std::string                         &getLiveImageUrl() const;
		const std::optional<Time>                 &getLockedAt() const;
		const std::optional<json>                 &getMandatoryDonation() const;
		std::vector<std::shared_ptr<Match>>       getMatches() const;
		size_t                                    getMaxPredictionsPerUser() const;
		const std::string                         &getName() const;
		const json                                &getNonEliminationTournamentData() const;
		bool                                      areUsersNotifiedWhenMatchesOpen() const;
		bool                                      areUsersNotifiedWhenTheTournamentEnds() const;
		const std::optional<json>                 &getOnlyStartMatchesWithStations() const;
		bool                                      isSignupOpen() const;
		std::vector<std::shared_ptr<Participant>> getParticipants() const;
		size_t                                    getParticipantsCount() const;
		bool                                      isParticipantsLocked() const;
		bool                                      isParticipantsSwappable() const;
		bool                                      canPredictTheLosersBracket() const;
		size_t                                    getPredictionMethod() const;
		const std::optional<Time>                 &getPredictionsOpenedAt() const;
		bool                                      isPrivate() const;
		const std::optional<json>                 &getProgramClassificationIdsAllowed() const;
		const std::optional<size_t>               &getProgramId() const;
		size_t                                    getProgressMeter() const;
		float                                     getPtsForBye() const;
		float                                     getPtsForGameTie() const;
		float                                     getPtsForGameWin() const;
		float                                     getPtsForMatchTie() const;
		float                                     getPtsForMatchWin() const;
		bool                                      arePublicPredictionsBeforeStartTimeAllowed() const;
		bool                                      isQuickAdvanceEnabled() const;
		bool                                      isRanked() const;
		const std::string                         &getRankedBy() const;
		float                                     getRegistrationFee() const;
		const std::string                         &getRegistrationType() const;
		bool                                      requiresScoreAgreement() const;
		bool                                      areReviewMandatoryBeforeFinalizing() const;
		size_t                                    getRrIterations() const;
		float                                     getRrPtsForGameTie() const;
		float                                     getRrPtsForGameWin() const;
		float                                     getRrPtsForMatchTie() const;
		float                                     getRrPtsForMatchWin() const;
		bool                                      isPairingsSequential() const;
		const std::optional<json>                 &getShowParticipantCountry() const;
		bool                                      areRoundsShown() const;
		const std::string                         &getSignUpUrl() const;
		const std::optional<json>                 &getSignupCap() const;
		const std::optional<json>                 &getSpam() const;
		bool                                      areParticipantsSplit() const;
		const Time                                &getStartAt() const;
		const std::optional<Time>                 &getStartedAt() const;
		const std::optional<Time>                 &getStartedCheckingInAt() const;
		const std::string                         &getState() const;
		const std::optional<json>                 &getSubdomain() const;
		size_t                                    getSwissRounds() const;
		bool                                      isTeamConvertable() const;
		bool                                      hasTeams() const;
		const std::vector<std::string>            &getTieBreaks() const;
		const std::optional<size_t>               &getTournamentRegistrationId() const;
		const std::string                         &getTournamentType() const;
		const std::optional<Time>                 &getUpdatedAt() const;
		const std::string                         &getUrl() const;
	};
}


#endif //CHALLONGELIB_TOURNAMENT_HPP
