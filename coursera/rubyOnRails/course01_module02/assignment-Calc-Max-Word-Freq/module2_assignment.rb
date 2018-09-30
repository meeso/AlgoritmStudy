class LineAnalyzer
  attr_accessor :highest_wf_count, :highest_wf_words, :content, :line_number     

  def initialize (content, line_number)
    self.content = content
    self.line_number = line_number
    self.calculate_word_frequency()
    return self
  end 

  def calculate_word_frequency
    word_frequency = Hash.new(0)
    self.content.split.each do |word|
      word_frequency[word.downcase] += 1
    end

    self.highest_wf_words = []

    word_frequency.each do |word, frequency|
      if frequency == word_frequency.values.max 
        self.highest_wf_words << word
        self.highest_wf_count = frequency
      end
    end
  end
end

class Solution
  attr_accessor :analyzers,:highest_count_across_lines, :highest_count_words_across_lines
  def initialize ()
    self.analyzers = []
  end 
  def analyze_file()
    Solution.new()
    num = 0
    if File.exist? 'test.txt'
      File.foreach('test.txt') do |line|
        self.analyzers << LineAnalyzer.new(line, num)
        num+=1
      end
    end
  end
  def calculate_line_with_highest_frequency()
    self.highest_count_across_lines = 0
    self.highest_count_words_across_lines = []

    self.analyzers.each do |lineAnalyzer|
      if lineAnalyzer.highest_wf_count > self.highest_count_across_lines
        self.highest_count_across_lines = lineAnalyzer.highest_wf_count 
#        self.highest_count_words_across_lines << lineanalyer.highest_wf_words
      end
    end
    self.analyzers.each do |lineAnalyzer|
      if lineAnalyzer.highest_wf_count == self.highest_count_across_lines
        self.highest_count_words_across_lines << lineAnalyzer
      end
    end
  end

  def print_highest_word_frequency_across_lines()
    puts "The following words have the highest word per line:"

    self.highest_count_words_across_lines.each do |lineAnalyzer|
      puts "#{lineAnalyzer.highest_wf_count} (appears in line #{lineAnalyzer.line_number})" 
    end
  end
end
