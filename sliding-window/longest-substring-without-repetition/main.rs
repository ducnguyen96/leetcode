struct Solution {}

impl Solution {
    pub fn can_construct(ransom_note: String, magazine: String) -> bool {
        let mut magazine_map = std::collections::HashMap::new();
        for c in magazine.chars() {
            let count = magazine_map.entry(c).or_insert(0);
            *count += 1;
        }
        for c in ransom_note.chars() {
            let count = magazine_map.entry(c).or_insert(0);
            if *count == 0 {
                return false;
            }
            *count -= 1;
        }
        true
    }
}

fn main() {
    let ransom_note = "a".to_string();
    let magazine = "ab".to_string();
    let result = Solution::can_construct(ransom_note, magazine);
    println!("{}", result);
}
