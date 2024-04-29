// COPYRIGHT 2024 apacicco
#ifndef _SONG_RECORDING_H_
#define _SONG_RECORDING_H_

#include<string>
using std::string;
#include<iostream>
using std::ostream;

namespace csce240_programming_assignment_5 {
class SongRecording {
friend ostream& operator << (ostream&, const SongRecording&);
 public:
  explicit SongRecording(string title = "untitled",
    string primary_artist = "unknown",
    int track_length = 0, int num_of_artists = 1);
  SongRecording(const SongRecording& to_copy); 
  SongRecording& operator = (const SongRecording& right);
  ~SongRecording() {
     delete [] _artist_name;
  }
  string GetTitle() const { return _title; }
  void SetTitle(string t);
  int GetNumArtists() const { return _artist_num; }
  void SetNumArtists(int);
  void SetArtist(string n, int i = 1);
  string GetArtist(int num = 1) const;
  int GetTrackLength() const { return _time_in_secs; }
  void SetTrackLength(int time);
 private:
  string _title;
  string * _artist_name;
  int _artist_num;
  int _time_in_secs;
};  // namespace csce240_programming_assignment_5
}

#endif  //  _HOME_APACICCO_CSCE240WORK_ASSIGNMENT5_SONGRECORDING_H_