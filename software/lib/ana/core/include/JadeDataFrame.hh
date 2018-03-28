#ifndef JADEPIX_JADEDATAFRAME
#define JADEPIX_JADEDATAFRAME

#include "JadeSystem.hh"

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
#include <chrono>


class DLLEXPORT JadeDataFrame{
 public:
  JadeDataFrame(const std::string &data);
  JadeDataFrame(std::string &&data);
  JadeDataFrame(size_t nraw);
  JadeDataFrame() = delete;
  virtual ~JadeDataFrame();
  virtual void Decode();
  std::string& RawDataString();
  std::string& DescriptionString();
  uint32_t GetFrameCount() const;
  std::chrono::system_clock::time_point& TimeStamp();
  bool IsInMatrix(size_t x, size_t y) const;
  int16_t GetHitValue(size_t x, size_t y) const;
  std::vector<int16_t> GetFrameData() const;
  uint32_t GetMatrixLowX() const;
  uint32_t GetMatrixLowY() const;
  uint32_t GetMatrixHighX() const;
  uint32_t GetMatrixHighY() const;
  uint32_t GetMatrixSizeX() const;
  uint32_t GetMatrixSizeY() const;
  void Print(std::ostream& os, size_t ws = 0) const;

  bool IsInEdge(size_t x, size_t y) const;
  void SetFrameCDS(std::vector<int16_t>&);
  std::vector<int16_t> GetFrameCDS();
  std::map<std::pair<size_t,size_t>,int16_t> CalFrameSeed(std::vector<int16_t>&);
  std::map<std::pair<size_t,size_t>,int16_t> GetFrameSeed();
  std::vector<int16_t> GetFrameCluster();
  JadeDataFrame operator-(JadeDataFrame &df);

 private:
  bool m_is_decoded;
  std::string m_data_raw;
  std::string m_description;
  std::chrono::system_clock::time_point m_ts;
  uint32_t m_frame_n;
  uint16_t m_offset_x;
  uint16_t m_offset_y;
  uint16_t m_n_x;
  uint16_t m_n_y;
  std::vector<int16_t> m_data;
  std::vector<int16_t> m_cds_frame_adc;
  std::map<std::pair<size_t, size_t>, int16_t> m_seed; 
  std::vector<int16_t> m_cluster;
  int16_t m_pix_seed_thr; 
  int16_t m_pix_clus_thr; 
  size_t m_cluster_size;
};

using JadeDataFrameSP = std::shared_ptr<JadeDataFrame>;

#endif
