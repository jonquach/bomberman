#ifndef		PAUSE_HPP_
# define	PAUSE_HPP_

class Pause
{
public:
	Pause();
	~Pause();

static void		resume();
static void		restart();
static void		save();
static void		load();
static void		quit();

	/* data */
};

#endif