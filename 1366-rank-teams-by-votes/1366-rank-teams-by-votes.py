class Solution:
    def rankTeams(self, votes):
        n = len(votes[0])

        count = {}

        for team in votes[0]:
            count[team] = [0] * n

        for vote in votes:
            for i in range(n):
                team = vote[i]
                count[team][i] += 1

        teams = list(count.keys())

        teams.sort(key=lambda team: (
            [-x for x in count[team]],
            team
        ))

        return ''.join(teams)